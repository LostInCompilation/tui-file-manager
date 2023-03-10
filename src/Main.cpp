//
//  Main.cpp
//  tui-file-manager
//
//  Created by Marc Schöndorf on 07.03.23.
//

#include "Main.h"

using namespace ftxui;

std::string GetAppVersion()
{
    return TUIFM_APP_NAME + " - Version: " + TUIFM_VERSION_STRING;
}

int main()
{
    GaugeDirection a;
    
    CLI::App app(TUIFM_APP_DESCRIPTION, TUIFM_APP_NAME);
    //app.get_formatter()->column_width(40);
    app.get_formatter()->label("TEXT", "STRING");
    app.footer("This is a footer!");
    
    // Enable Windows style arguments
#ifdef TARGET_OS_WINDOWS
    app.allow_windows_style_options();
#endif
    
    bool showHiddenFiles = true;
    std::string startingPath = "";
    
    app.set_version_flag("-v,--version", GetAppVersion)->group("Info");
    app.add_option("-p,--path", startingPath, "Path to start in")->required()->group("Settings");
    app.add_option("-a,-b,--multiple", "Multiple");
    app.add_option("--only-long", "Long");
    app.add_flag("--hidden,--hide", showHiddenFiles, "Show or hide hidden files")->group("Settings");
    app.add_option("-r", "Short req.")->required();
    app.add_option("-s", "Short");
    
    //app.add_flag("--hidden,!--no-hidden", showHiddenFiles, "Show or hide hidden files");
    //app.add_flag("--monitor,!--no-monitor", showHiddenFiles, "Monitor the directories for file system changes");
    
    
    // Parsee arguments
    //CLI11_PARSE(app, CLI::argc(), CLI::argv());
    
    // Debug
    const char* argv[2] = {"bin_path", "-h"};
    CLI11_PARSE(app, 2, argv);
    //app.parse(1, &argv[0]);
    
    std::cout << "Start path: " << startingPath << std::endl
                << "Show hidden: " << std::boolalpha << showHiddenFiles << std::endl;
    
    
    // TUI
    ScreenInteractive screen = ScreenInteractive::Fullscreen();
    
    screen.dimx();
    
    std::shared_ptr<FileManagerUI> fui = ftxui::Make<FileManagerUI>(screen.ExitLoopClosure());
    
    //Component container = Container::Horizontal({fui});
    
    auto renderer = Renderer(fui, [&] {
        return //hbox({
        fui->Render();
        //});
    });
    
    screen.Loop(renderer);
    
    
    
    
//    // Simple menu
//    std::vector<std::string> menu_entries = {"0%", "10%", "20%", "30%", "40%", "50%", "60%", "70%", "80%", "90%"};
//    
//    auto menu_option = MenuOption::Vertical();
//    menu_option.on_enter = screen.ExitLoopClosure();
//    
//    auto menu_option2 = MenuOption::Vertical();
//    menu_option2.on_enter = screen.ExitLoopClosure();
//    
//    int menu_selected = 0;
//    int menu_selected2 = 0;
//    Component menu = Menu(&menu_entries, &menu_selected, &menu_option);
//    Component menu2 = Menu(&menu_entries, &menu_selected2, &menu_option2);
    
    // Main container
    //Component container = Container::Horizontal({menu, menu2});
    
    // Renderer
//    auto renderer = Renderer(container, [&] {
//        return window(text("Window") | bold | center,
//        vbox({
//            hcenter(bold(text(startingPath))),
//            separator(),
//            hbox({
//                menu->Render() ,
//                separator(),
//                menu2->Render()  | flex
//            })
//        }) | border);
//    });
    
    
//    auto mainView =
//        hbox({
//            menu->Render() | frame,
//            separator(),
//            menu2->Render() | flex | frame
//    });
//
//    auto main_window =
//        window(
//            text("Window") | bold | center,
//            vbox({
//                hcenter(bold(text("startingPath"))),
//                separator(),
//                mainView | flex,
//                //separator(),
//                //statusLine
//                })
//            );
//
//
//    auto renderer = Renderer(main_window, [&] {
//        return main_window;
//    });
    
    return 0;
}
