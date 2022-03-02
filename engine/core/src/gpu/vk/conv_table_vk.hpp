#ifndef _TEMPEH_GPU_CONV_TABLE_VK_HPP
#define _TEMPEH_GPU_CONV_TABLE_VK_HPP 1

#include "vk.hpp"

namespace Tempeh::GPU
{
    static inline constexpr ResultCode parse_error_vk(VkResult result)
    {
        switch (result) {
            case VK_ERROR_OUT_OF_HOST_MEMORY:
            case VK_ERROR_OUT_OF_DEVICE_MEMORY:
                return ResultCode::OutOfMemory;
            case VK_ERROR_INITIALIZATION_FAILED:
                return ResultCode::InitializationFailed;
            default:
                return ResultCode::InternalError;
        }
    }

    static inline void convert_device_limits(const VkPhysicalDeviceLimits& limits, DeviceLimits& device_limits)
    {
        device_limits.max_texture_dimension_1d = limits.maxImageDimension1D;
        device_limits.max_texture_dimension_2d = limits.maxImageDimension2D;
        device_limits.max_texture_dimension_3d = limits.maxImageDimension3D;
        device_limits.max_texture_dimension_cube = limits.maxImageDimensionCube;
        device_limits.max_texture_array_layers = limits.maxImageArrayLayers;
    }

    static inline constexpr VkFormat convert_format_vk(TextureFormat format)
    {
        switch (format) {
            case TextureFormat::R_8_Sint:
                return VK_FORMAT_R8_SINT;
            case TextureFormat::R_8_Uint:
                return VK_FORMAT_R8_UINT;
            case TextureFormat::R_8_Snorm:
                return VK_FORMAT_R8_SNORM;
            case TextureFormat::R_8_Unorm:
                return VK_FORMAT_R8_UNORM;

            case TextureFormat::RG_8_8_Sint:
                return VK_FORMAT_R8G8_SINT;
            case TextureFormat::RG_8_8_Uint:
                return VK_FORMAT_R8G8_UINT;
            case TextureFormat::RG_8_8_Snorm:
                return VK_FORMAT_R8G8_SNORM;
            case TextureFormat::RG_8_8_Unorm:
                return VK_FORMAT_R8G8_UNORM;

            case TextureFormat::RGBA_8_8_8_8_Sint:
                return VK_FORMAT_R8G8B8A8_SINT;
            case TextureFormat::RGBA_8_8_8_8_Uint:
                return VK_FORMAT_R8G8B8A8_UINT;
            case TextureFormat::RGBA_8_8_8_8_Snorm:
                return VK_FORMAT_R8G8B8A8_SNORM;
            case TextureFormat::RGBA_8_8_8_8_Unorm:
                return VK_FORMAT_R8G8B8A8_UNORM;
            case TextureFormat::RGBA_8_8_8_8_Srgb:
                return VK_FORMAT_R8G8B8A8_SRGB;

            case TextureFormat::BGRA_8_8_8_8_Sint:
                return VK_FORMAT_B8G8R8A8_SINT;
            case TextureFormat::BGRA_8_8_8_8_Uint:
                return VK_FORMAT_B8G8R8A8_UINT;
            case TextureFormat::BGRA_8_8_8_8_Snorm:
                return VK_FORMAT_B8G8R8A8_UNORM;
            case TextureFormat::BGRA_8_8_8_8_Unorm:
                return VK_FORMAT_B8G8R8A8_UNORM;
            case TextureFormat::BGRA_8_8_8_8_Srgb:
                return VK_FORMAT_B8G8R8A8_SRGB;

            case TextureFormat::R_16_Sint:
                return VK_FORMAT_R16_SINT;
            case TextureFormat::R_16_Uint:
                return VK_FORMAT_R16_UINT;
            case TextureFormat::R_16_Float:
                return VK_FORMAT_R16_SFLOAT;
            
            case TextureFormat::RG_16_16_Sint:
                return VK_FORMAT_R16G16_SINT;
            case TextureFormat::RG_16_16_Uint:
                return VK_FORMAT_R16G16_UINT;
            case TextureFormat::RG_16_16_Float:
                return VK_FORMAT_R16G16_SFLOAT;

            case TextureFormat::RGBA_16_16_16_16_Sint:
                return VK_FORMAT_R16G16B16A16_SINT;
            case TextureFormat::RGBA_16_16_16_16_Uint:
                return VK_FORMAT_R16G16B16A16_UINT;
            case TextureFormat::RGBA_16_16_16_16_Float:
                return VK_FORMAT_R16G16B16A16_SFLOAT;

            case TextureFormat::R_32_Sint:
                return VK_FORMAT_R32_SINT;
            case TextureFormat::R_32_Uint:
                return VK_FORMAT_R32_UINT;
            case TextureFormat::R_32_Float:
                return VK_FORMAT_R32_SFLOAT;

            case TextureFormat::RG_32_32_Sint:
                return VK_FORMAT_R32G32_SINT;
            case TextureFormat::RG_32_32_Uint:
                return VK_FORMAT_R32G32_UINT;
            case TextureFormat::RG_32_32_Float:
                return VK_FORMAT_R32G32_SFLOAT;

            case TextureFormat::RGBA_32_32_32_32_Sint:
                return VK_FORMAT_R32G32B32A32_SINT;
            case TextureFormat::RGBA_32_32_32_32_Uint:
                return VK_FORMAT_R32G32B32A32_UINT;
            case TextureFormat::RGBA_32_32_32_32_Float:
                return VK_FORMAT_R32G32B32A32_SFLOAT;

            case TextureFormat::D_16_Unorm:
                return VK_FORMAT_D16_UNORM;
            case TextureFormat::D_24_Unorm_S_8_Uint:
                return VK_FORMAT_D24_UNORM_S8_UINT;
            case TextureFormat::D_32_Float:
                return VK_FORMAT_D32_SFLOAT;
            case TextureFormat::D_32_Float_S_8_Uint:
                return VK_FORMAT_D32_SFLOAT_S8_UINT;

            default:
                break;
        }

        return VK_FORMAT_UNDEFINED;
    }

    static inline constexpr VkFormat convert_vertex_format_vk(VertexFormat format)
    {
        switch (format) {
            case VertexFormat::Uint32:
                return VK_FORMAT_R32_UINT;
            case VertexFormat::Sint32:
                return VK_FORMAT_R32_SINT;
            case VertexFormat::Float32:
                return VK_FORMAT_R32_SFLOAT;

            case VertexFormat::Uint32x2:
                return VK_FORMAT_R32G32_UINT;
            case VertexFormat::Sint32x2:
                return VK_FORMAT_R32G32_SINT;
            case VertexFormat::Float32x2:
                return VK_FORMAT_R32G32_SFLOAT;
            
            case VertexFormat::Uint32x3:
                return VK_FORMAT_R32G32B32_UINT;
            case VertexFormat::Sint32x3:
                return VK_FORMAT_R32G32B32_SINT;
            case VertexFormat::Float32x3:
                return VK_FORMAT_R32G32B32_SFLOAT;
            
            case VertexFormat::Uint32x4:
                return VK_FORMAT_R32G32B32A32_UINT;
            case VertexFormat::Sint32x4:
                return VK_FORMAT_R32G32B32A32_SINT;
            case VertexFormat::Float32x4:
                return VK_FORMAT_R32G32B32A32_SFLOAT;
        }

        return VK_FORMAT_UNDEFINED;
    }

    static inline constexpr std::pair<VkMemoryPropertyFlags, VkMemoryPropertyFlags> convert_memory_usage_vk(MemoryUsage usage)
    {
        switch (usage) {
            case MemoryUsage::Default:
                return std::make_pair(VkMemoryPropertyFlags{ VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT }, VkMemoryPropertyFlags{});
            case MemoryUsage::Upload:
                return std::make_pair(VkMemoryPropertyFlags{ VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT },
                                      VkMemoryPropertyFlags{ VK_MEMORY_PROPERTY_HOST_COHERENT_BIT});
            case MemoryUsage::Readback:
                return std::make_pair(VkMemoryPropertyFlags{ VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT },
                                      VkMemoryPropertyFlags{ VK_MEMORY_PROPERTY_HOST_COHERENT_BIT |
                                                             VK_MEMORY_PROPERTY_HOST_CACHED_BIT });
            case MemoryUsage::Shared:
                return std::make_pair(VkMemoryPropertyFlags{ VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT |
                                                             VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT },
                                      VkMemoryPropertyFlags{ VK_MEMORY_PROPERTY_HOST_COHERENT_BIT });
        }

        return std::make_pair(VkMemoryPropertyFlags{ VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT }, VkMemoryPropertyFlags{});
    }

    static inline constexpr std::pair<VkImageUsageFlags, VkFormatFeatureFlags> convert_texture_usage_vk(TextureUsageFlags usage)
    {
        VkImageUsageFlags image_usage = (bit_match(usage, TextureUsage::TransferSrc) ? VK_IMAGE_USAGE_TRANSFER_SRC_BIT : 0) |
            (bit_match(usage, TextureUsage::TransferDst) ? VK_IMAGE_USAGE_TRANSFER_DST_BIT : 0) |
            (bit_match(usage, TextureUsage::Sampled) ? VK_IMAGE_USAGE_SAMPLED_BIT : 0) |
            (bit_match(usage, TextureUsage::ColorAttachment) ? VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT : 0) |
            (bit_match(usage, TextureUsage::DepthStencilAttachment) ? VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT : 0) |
            (bit_match(usage, TextureUsage::Storage) ? VK_IMAGE_USAGE_STORAGE_BIT : 0);

        VkFormatFeatureFlags format_features = (bit_match(usage, TextureUsage::TransferSrc) ? VK_FORMAT_FEATURE_TRANSFER_SRC_BIT : 0) |
            (bit_match(usage, TextureUsage::TransferDst) ? VK_FORMAT_FEATURE_TRANSFER_DST_BIT : 0) |
            (bit_match(usage, TextureUsage::Sampled) ? VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT | VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT : 0) |
            (bit_match(usage, TextureUsage::ColorAttachment) ? VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT | VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT : 0) |
            (bit_match(usage, TextureUsage::DepthStencilAttachment) ? VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT : 0) |
            (bit_match(usage, TextureUsage::Storage) ? VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT : 0);

        return std::make_pair(image_usage, format_features);
    }

    static inline constexpr VkBufferUsageFlags convert_buffer_usage_vk(BufferUsageFlags usage)
    {
        return (bit_match(usage, BufferUsage::TransferSrc) ? VK_BUFFER_USAGE_TRANSFER_SRC_BIT : 0) |
            (bit_match(usage, BufferUsage::TransferDst) ? VK_BUFFER_USAGE_TRANSFER_DST_BIT : 0) |
            (bit_match(usage, BufferUsage::Uniform) ? VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT : 0) |
            (bit_match(usage, BufferUsage::Index) ? VK_BUFFER_USAGE_VERTEX_BUFFER_BIT : 0) |
            (bit_match(usage, BufferUsage::Vertex) ? VK_BUFFER_USAGE_INDEX_BUFFER_BIT : 0) |
            (bit_match(usage, BufferUsage::Storage) ? VK_BUFFER_USAGE_STORAGE_BUFFER_BIT : 0) |
            (bit_match(usage, BufferUsage::Indirect) ? VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT : 0);
    }

    static inline constexpr VkAttachmentLoadOp convert_load_op_vk(LoadOp load_op)
    {
        switch (load_op) {
            case LoadOp::Load:
                return VK_ATTACHMENT_LOAD_OP_LOAD;
            default:
                return VK_ATTACHMENT_LOAD_OP_CLEAR;
        }
    }

    static inline constexpr VkAttachmentStoreOp convert_store_op_vk(StoreOp store_op)
    {
        switch (store_op) {
            case StoreOp::Store:
                return VK_ATTACHMENT_STORE_OP_STORE;
            default:
                return VK_ATTACHMENT_STORE_OP_DONT_CARE;
        }
    }

    static inline constexpr VkFilter convert_texture_filtering_vk(TextureFiltering filter)
    {
        switch (filter) {
            case TextureFiltering::Linear:
                return VK_FILTER_LINEAR;
            default:
                return VK_FILTER_NEAREST;
        }
    }

    static inline constexpr VkSamplerMipmapMode convert_mipmap_filtering_vk(TextureFiltering filter)
    {
        switch (filter) {
            case TextureFiltering::Linear:
                return VK_SAMPLER_MIPMAP_MODE_LINEAR;
            default:
                return VK_SAMPLER_MIPMAP_MODE_NEAREST;
        }
    }

    static inline constexpr VkSamplerAddressMode convert_texture_addressing_vk(TextureAddressing addressing)
    {
        switch (addressing) {
            case TextureAddressing::Mirror:
                return VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT;
            case TextureAddressing::Clamp:
                return VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
            default:
                return VK_SAMPLER_ADDRESS_MODE_REPEAT;
        }
    }

    static inline constexpr VkCompareOp convert_compare_op_vk(CompareOp compare_op)
    {
        switch (compare_op) {
            case CompareOp::Less:
                return VK_COMPARE_OP_LESS;
            case CompareOp::Equal:
                return VK_COMPARE_OP_EQUAL;
            case CompareOp::LessEqual:
                return VK_COMPARE_OP_LESS_OR_EQUAL;
            case CompareOp::Greater:
                return VK_COMPARE_OP_GREATER;
            case CompareOp::NotEqual:
                return VK_COMPARE_OP_NOT_EQUAL;
            case CompareOp::GreaterEqual:
                return VK_COMPARE_OP_GREATER_OR_EQUAL;
            case CompareOp::Always:
                return VK_COMPARE_OP_ALWAYS;
            default:
                return VK_COMPARE_OP_NEVER;
        }
    }

    static inline VkStencilOp convert_stencil_op_vk(StencilOp stencil_op)
    {
        switch (stencil_op) {
            case StencilOp::Keep:
                return VK_STENCIL_OP_KEEP;
            case StencilOp::Zero:
                return VK_STENCIL_OP_ZERO;
            case StencilOp::Replace:
                return VK_STENCIL_OP_REPLACE;
            case StencilOp::Invert:
                return VK_STENCIL_OP_INVERT;
            case StencilOp::IncrementClamp:
                return VK_STENCIL_OP_INCREMENT_AND_CLAMP;
            case StencilOp::DecrementClamp:
                return VK_STENCIL_OP_DECREMENT_AND_CLAMP;
            case StencilOp::Increment:
                return VK_STENCIL_OP_INCREMENT_AND_WRAP;
            case StencilOp::Decrement:
                return VK_STENCIL_OP_DECREMENT_AND_WRAP;
            default:
                assert(false && "This section should be unreachable");
        }

        return VK_STENCIL_OP_KEEP;
    }

    template<bool Color>
    static inline VkBlendFactor convert_blend_factor_vk(BlendFactor blend_factor)
    {
        switch (blend_factor) {
            case BlendFactor::Zero:
                return VK_BLEND_FACTOR_ZERO;
            case BlendFactor::One:
                return VK_BLEND_FACTOR_ONE;
            case BlendFactor::SrcColor:
                return VK_BLEND_FACTOR_SRC_COLOR;
            case BlendFactor::OneMinusSrcColor:
                return VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR;
            case BlendFactor::DstColor:
                return VK_BLEND_FACTOR_DST_COLOR;
            case BlendFactor::OneMinusDstColor:
                return VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR;
            case BlendFactor::SrcAlpha:
                return VK_BLEND_FACTOR_SRC_ALPHA;
            case BlendFactor::OneMinusSrcAlpha:
                return VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
            case BlendFactor::DstAlpha:
                return VK_BLEND_FACTOR_DST_ALPHA;
            case BlendFactor::OneMinusDstAlpha:
                return VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA;
            case BlendFactor::Constant:
                return Color ? VK_BLEND_FACTOR_CONSTANT_COLOR
                             : VK_BLEND_FACTOR_CONSTANT_ALPHA;
            case BlendFactor::OneMinusConstant:
                return Color ? VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR
                             : VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA;
            default:
                assert(false);
        }

        return VK_BLEND_FACTOR_ZERO;
    }

    static inline VkBlendOp convert_blend_op_vk(BlendOp blend_op)
    {
        switch (blend_op) {
            case BlendOp::Add:
                return VK_BLEND_OP_ADD;
            case BlendOp::Subtract:
                return VK_BLEND_OP_SUBTRACT;
            case BlendOp::InvSubtract:
                return VK_BLEND_OP_REVERSE_SUBTRACT;
            case BlendOp::Min:
                return VK_BLEND_OP_MIN;
            case BlendOp::Max:
                return VK_BLEND_OP_MAX;
            default:
                assert(false);
        }

        return VK_BLEND_OP_ADD;
    }

    static inline void texture_layout_transition_vk(
        VkImageLayout new_layout,
        const VkImageSubresourceRange& subresource_range,
        VkImage image,
        VkImageLayout& old_layout,
        VkPipelineStageFlags& stage_src,
        VkPipelineStageFlags& stage_dst,
        VkImageMemoryBarrier& barrier)
    {
        switch (old_layout) {
            case VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL:
                stage_src |=
                    VK_PIPELINE_STAGE_VERTEX_SHADER_BIT |
                    VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT |
                    VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT;
                barrier.srcAccessMask = VK_ACCESS_SHADER_READ_BIT;
                break;
            case VK_IMAGE_LAYOUT_GENERAL:
                stage_src |=
                    VK_PIPELINE_STAGE_VERTEX_SHADER_BIT |
                    VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT |
                    VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT;
                barrier.srcAccessMask = VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_SHADER_WRITE_BIT;
                break;
            case VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL:
                stage_src |= VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
                barrier.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
                break;
            case VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL:
                stage_src |= VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT | VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT;
                barrier.srcAccessMask = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
                break;
            case VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL:
                stage_src |= VK_PIPELINE_STAGE_TRANSFER_BIT;
                barrier.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
                break;
            case VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL:
                stage_src |= VK_PIPELINE_STAGE_TRANSFER_BIT;
                barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
                break;
            default:
                stage_src |= VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
                barrier.srcAccessMask = 0;
                break;
        }

        switch (new_layout) {
            case VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL:
                stage_dst |=
                    VK_PIPELINE_STAGE_VERTEX_SHADER_BIT |
                    VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT |
                    VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT;
                barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
                break;
            case VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL:
                stage_dst |= VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
                barrier.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
                break;
            case VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL:
                stage_dst |= VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT | VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT;
                barrier.dstAccessMask = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
                break;
            case VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL:
                stage_dst |= VK_PIPELINE_STAGE_TRANSFER_BIT;
                barrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
                break;
            case VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL:
                stage_dst |= VK_PIPELINE_STAGE_TRANSFER_BIT;
                barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
                break;
            default:
                stage_dst |= VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT;
                barrier.dstAccessMask = 0;
                break;
        }

        barrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        barrier.pNext = nullptr;
        barrier.oldLayout = old_layout;
        barrier.newLayout = new_layout;
        barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        barrier.image = image;
        barrier.subresourceRange = subresource_range;

        old_layout = new_layout;
    }
}

#endif