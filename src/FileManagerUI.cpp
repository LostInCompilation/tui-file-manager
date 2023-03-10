//
//  UI.cpp
//  tui-file-manager
//
//  Created by Marc Schöndorf on 07.03.23.
//

#include "Main.h"

using namespace ftxui;

FileManagerUI::FileManagerUI(std::function<void()> quitFunc)
    : m_QuitFunc(quitFunc)
{
    // Simple menu
    m_MenuOption = MenuOption::Vertical();
    m_MenuOption.on_enter = m_QuitFunc;
    
    m_MenuOption2 = MenuOption::Vertical();
    m_MenuOption2.on_enter = m_QuitFunc;
    
    m_Menu = Menu(&m_MenuElements, &m_MenuSelection, &m_MenuOption);
    m_Menu2 = Menu(&m_MenuElements2, &m_MenuSelection2, &m_MenuOption2);
    
    
    
    auto para = Renderer([&] { return paragraph(longText); });
    
    
    auto split = ResizableSplitLeft(m_Menu2, para, &m_SplitLeftSize);
    m_Split = ResizableSplitLeft(m_Menu, split, &m_SplitLeftSize2);

    
    
    //m_Split = ResizableSplitLeft(menuSplit, para, &m_SplitLeftSize2);
    
    //m_Frame = Container::Horizontal({m_Menu, m_Menu2});
    //m_Frame = Container::Horizontal({m_Split});
    
    // MenuView
//    m_MenuView = Renderer([&] {
//        return hbox({
//            m_Menu->Render() | frame,
//            separator(),
//            m_Menu2->Render() | flex | frame
//        });}
//    );
    
    Add(m_Split);
}

ftxui::Element FileManagerUI::Render()
{
//    if(m_SplitLeftSize < 10)
//        m_SplitLeftSize = 10;
//    if(m_SplitLeftSize > 50)
//        m_SplitLeftSize = 50;
    
    auto menuView =
        hbox({
            m_Split->Render(),
            //separator(),
            //paragraph(longText)
    });
    
    auto main_window =
        window(
            text("Window") | bold | center,
            vbox({
                hcenter(bold(text("startingPath - Split: " + std::to_string(m_SplitLeftSize)))),
                separator(),
                menuView | flex,
                //separator(),
                //statusLine
                })
            );
    
    
    
    
//    auto menuView =
//        hbox({
//            m_Menu->Render() | frame,
//            separator(),
//            m_Menu2->Render() | flex | frame
//    });
//
//    auto main_window =
//        window(
//            text("Window") | bold | center,
//            vbox({
//                hcenter(bold(text("startingPath"))),
//                separator(),
//                menuView | flex,
//                //separator(),
//                //statusLine
//                })
//            );
    
    return main_window;
}

bool FileManagerUI::OnEvent(ftxui::Event event)
{
    return ComponentBase::OnEvent(event);
}
