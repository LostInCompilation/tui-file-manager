//
//  Main.cpp
//  tui-file-manager
//
//  Created by Marc Schöndorf on 07.03.23.
//

#include "Main.h"

int main()
{
    CLI::App app("App description", "name");
    
    
    CLI11_PARSE(app, CLI::argc(), CLI::argv());
    
    
    
    
    auto screen = ftxui::ScreenInteractive::Fullscreen();
    
    std::cout << "Hello" << std::endl;
    
    UI ui;
    
    return 0;
}
