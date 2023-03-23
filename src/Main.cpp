//
//  Main.cpp
//  tui-file-manager
//
//  Created by Marc Schöndorf on 07.03.23.
//

#include "Main.h"

using namespace ftxui;

std::string GetAppVersionString()
{
    return TUIFM_APP_CMAKE_NAME + " - Version: " + TUIFM_VERSION_STRING;
}

#include "CLI/StringTools.hpp"

int main()
{
    //CLI::App app(TUIFM_APP_DESCRIPTION, TUIFM_APP_NAME);
    //CLI::App app{"My Prog description", "AppName"};
    CLI::App app("A long description\nNew line. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.", TUIFM_APP_CMAKE_NAME); //TUIFM_APP_NAME
    
    // Testing
    //app.get_formatter()->label("Usage", "Run");
    //app.usage("This is the usage.");
    
    //app.get_formatter()->column_width(30);
    
    app.get_formatter()->label("TEXT", "STRING");
    //app.footer("This is a footer!");
    app.footer("A long footer\nNew line. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.");
    
    // Enable Windows style arguments
#ifdef TARGET_OS_WINDOWS
    app.allow_windows_style_options();
#endif
    
    bool showHiddenFiles = true;
    std::string startingPath = "pax";
    int i = 0;
    
    app.set_help_all_flag("--help-all", "Expand all help");
    
    app.set_version_flag("-v,--version", GetAppVersionString)->group("INFO");
    app.add_option("-p,--path", startingPath, "Path to start in")->group("SETTINGS")->capture_default_str();//->required();
    app.add_option("-a,-b,-c,--multiple", i, "Multiple")->group("OPTIONS")->configurable();
    app.add_option("-d", i, "Multiple2")->group("gr42")->configurable();
    app.add_option("-k,-m,-n,-o,-q,-w,-e", "Long short names");
    app.add_option("--only-long", "Long")->configurable();
    app.add_flag("--hidden,--hide", showHiddenFiles, "Show or hide hidden files")->group("SETTINGS");
    app.add_option("-r", "Short req. Lorem ipsum dolor sit amet,\nconsetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est.");//->required();
    app.add_option("-s", "Short");
    app.add_option("-l,--this-is-a-very-long-option-for-testing", "Very long");
    
    // Positional
    app.add_option("pos", "A positional");
    //app.add_option("posreq", "A required positional")->required();
    app.add_option("longpos", "Consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum.");
    
    // Test for scrambled order of short and long options
    app.add_option("-x,--xlong,-y,--ylong", "Scrambled order");
    
    // Subcommand tests
    CLI::App* start = app.add_subcommand("startxxxxxxxxxxxxxxxxxxxxxxx", "A great subcommand");
    CLI::App* stop = app.add_subcommand("stop", "Do you really want to stop?");
    
    start->add_option("-f,--fileloooooooooong", "File name");
    stop->add_flag("-c,--count", "Counter");
    
    // Sub subcommand
    CLI::App* subsub = start->add_subcommand("subsub", "A sub subcommand for start");
    std::string subsubstr = "";
    subsub->add_flag("-j,--jsubsub", "Flag of sub subcommand");
    subsub->add_option("-g,--gstr", subsubstr, "Sub sub string")->group("SUBSUB GROUP");
    
    //std::cout << "CONFIG:\n" << app.config_to_str(true, true) << std::endl << "--------------------------------------------------\n";
    
    //app.add_flag("--hidden,!--no-hidden", showHiddenFiles, "Show or hide hidden files");
    //app.add_flag("--monitor,!--no-monitor", showHiddenFiles, "Monitor the directories for file system changes");
    
    
    // Parsee arguments
    //CLI11_PARSE(app, CLI::argc(), CLI::argv());
    
    // Debug
    const char* argv[4] = {"", "--help-all", "-p", " "};
    //const char* argv[2] = {"", "-h"};
    //const char* argv[3] = {"", "start", "-h"};
    CLI11_PARSE(app, 4, argv);

    
    
    
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
