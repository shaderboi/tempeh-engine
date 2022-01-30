#ifndef _TEMPEH_GPU_DEVICE_HPP
#define _TEMPEH_GPU_DEVICE_HPP

#include <tempeh/gpu/types.hpp>
#include <tempeh/gpu/detail/wrapper.hpp>
#include <tempeh/gpu/detail/device_impl.hpp>

#include <tempeh/gpu/command_list.hpp>
#include <tempeh/gpu/resource.hpp>

namespace Tempeh::GPU
{
    class Device : public Detail::Wrapper<Detail::DeviceImpl>
    {
    public:
        Device();
        Device(Detail::DeviceImpl* impl);
        Device(const Device& other);
        ~Device();

        DeviceResult<Texture> create_texture(const TextureDesc& desc);
        DeviceResult<Buffer> create_buffer(const BufferDesc& desc);
        DeviceResult<CommandList> create_command_list(const CommandListDesc& desc);
    };
}

#endif
