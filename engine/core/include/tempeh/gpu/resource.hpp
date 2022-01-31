#ifndef _TEMPEH_GPU_RESOURCE_HPP
#define _TEMPEH_GPU_RESOURCE_HPP

#include <tempeh/gpu/types.hpp>

namespace Tempeh::GPU
{
    class Texture
    {
    public:
        Texture();
        virtual ~Texture();
    };

    class Buffer
    {
    public:
        Buffer();
        virtual ~Buffer();
    };

    class GraphicsPipeline
    {
    public:
        GraphicsPipeline() { }
        virtual ~GraphicsPipeline() { }
    };
}

#endif