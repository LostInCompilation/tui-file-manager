//
//  Main.cpp
//  tui-file-manager
//
//  Created by Marc Schöndorf on 07.03.23.
//

#include "Main.h"

using namespace ftxui;

int main()
{
    CLI::App app(TUIFM_APP_DESCRIPTION, TUIFM_APP_NAME);
    
    // Enable Windows style arguments
#ifdef TARGET_OS_WINDOWS
    app.allow_windows_style_options();
#endif
    
    bool printVersion = false;
    bool showHiddenFiles = true;
    std::string startingPath = "";
    
    app.add_flag("-v,--version", printVersion, "Print App version");
    app.add_flag("--hidden,!--no-hidden", showHiddenFiles, "Show or hide hidden files");
    app.add_option("-p,--path", startingPath, "Path to start in");
    
    // Parsee arguments
    CLI11_PARSE(app, CLI::argc(), CLI::argv());
    
    if(printVersion)
    {
        std::cout << TUIFM_APP_NAME << " - Version: " << TUIFM_VERSION_STRING << std::endl;
        return 0;
    }
    
    std::cout << "Start path: " << startingPath << std::endl
                << "Show hidden: " << std::boolalpha << showHiddenFiles << std::endl;
    
    
    // TUI
    auto screen = ScreenInteractive::Fullscreen();
    
    // Simple menu
    std::vector<std::string> menu_entries = {"0%", "10%", "20%", "30%", "40%", "50%", "60%", "70%", "80%", "90%"};
    
    auto menu_option = MenuOption::Vertical();
    menu_option.on_enter = screen.ExitLoopClosure();
    
    int menu_selected = 0;
    Component menu = Menu(&menu_entries, &menu_selected, &menu_option);
    
    // Main container
    Component container = Container::Horizontal({menu});
    
    // Renderer
    auto renderer = Renderer(container, [&] {
        return vbox({
            hcenter(bold(text(startingPath))),
            separator(),
            menu->Render()
        }) | border;
    });
    
    screen.Loop(renderer);
    
    return 0;
}
