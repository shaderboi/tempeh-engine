#ifndef _TEMPEH_GPU_DEVICE_VK_H
#define _TEMPEH_GPU_DEVICE_VK_H

#include <tempeh/gpu/device.hpp>
#include <tempeh/gpu/types.hpp>
#include <memory>
#include <array>

#include "vk.hpp"

namespace Tempeh::GPU
{
    template<size_t MaxBuffer>
    class CommandManagerVK
    {
        using PoolBufferPair = std::pair<VkCommandPool, VkCommandBuffer>;

        VkDevice device = VK_NULL_HANDLE;
        std::array<PoolBufferPair, MaxBuffer> m_cmds{};

        CommandManagerVK(VkDevice device, u32 queue_family_index) :
            device(device)
        {
            VkCommandPoolCreateInfo cmd_pool_info{};
            cmd_pool_info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
            cmd_pool_info.flags = VK_COMMAND_POOL_CREATE_TRANSIENT_BIT;
            cmd_pool_info.queueFamilyIndex = queue_family_index;

            VkCommandBufferAllocateInfo cmd_buffer_info{};
            cmd_buffer_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
            cmd_buffer_info.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
            cmd_buffer_info.commandBufferCount = 1;

            for (auto& cmd : m_cmds) {
                VkResult result = 
                    vkCreateCommandPool(device, &cmd_pool_info, nullptr, &cmd.first);

                assert(!VULKAN_FAILED(result) && "Failed to create command pool");

                cmd_buffer_info.commandPool = cmd.first;
                result = vkAllocateCommandBuffers(device, &cmd_buffer_info, &cmd.last);

                assert(!VULKAN_FAILED(result) && "Failed to allocate command buffer");
            }
        }

        ~CommandManagerVK()
        {
            for (auto& cmd : m_cmds) {
                vkDestroyCommandPool(cmd.first);
            }
        }
    };

    class DeviceVK : public Device
    {
    public:
        static constexpr size_t max_command_buffers = 3;

        DeviceVK(
            VkInstance instance,
            VkPhysicalDevice physical_device,
            VkDevice device,
            u32 main_queue_index);

        ~DeviceVK();

        RefDeviceResult<Surface> create_surface(
            const std::shared_ptr<Window::Window>& window,
            const SurfaceDesc& desc) override final;

        RefDeviceResult<Texture> create_texture(const TextureDesc& desc) override final;
        RefDeviceResult<Buffer> create_buffer(const BufferDesc& desc) override final;

        void begin_frame() override final;
        void end_frame() override final;
        void swap_buffer() override final;

        static RefDeviceResult<Device> initialize(bool prefer_high_performance);

    private:
        VkInstance m_instance;
        VkPhysicalDevice m_physical_device;
        VkDevice m_device;
        u32 m_main_queue_index;
        VkQueue m_main_queue = VK_NULL_HANDLE;

        std::unique_ptr<CommandManagerVK<max_command_buffers>> m_cmd_manager;

        VkSurfaceKHR create_surface_glfw(const std::shared_ptr<Window::Window>& window);
    };
}

#endif