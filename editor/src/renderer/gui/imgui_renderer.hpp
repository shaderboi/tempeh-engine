#ifndef _TEMPEH_RENDERER_GUI_GUI_IMGUI_RENDERER_HPP
#define _TEMPEH_RENDERER_GUI_GUI_IMGUI_RENDERER_HPP

#include <imgui.h>

#include <utility>
#include <memory>

#include <tempeh/common/typedefs.hpp>
#include <tempeh/window/window.hpp>

#include "renderer.hpp"
#include "../render_context.hpp"

namespace TempehEditor::Renderer::GUI
{

    class GUIImGuiRenderer : public GUIRenderer
    {
    private:
        Rc<TempehEditor::Renderer::RenderContext> render_context;
    public:
        GUIImGuiRenderer(
            Rc<Tempeh::Window::Window> window,
            Rc<TempehEditor::Renderer::RenderContext> render_context);

        void predraw() override;
        void draw() override;
        void postdraw() override;
    };

}

#endif
