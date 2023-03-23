//
//  FileManagerUI.h
//  tui-file-manager
//
//  Created by Marc Schöndorf on 07.03.23.
//

#ifndef FileManagerUI_h
#define FileManagerUI_h

class FileManagerUI : public ftxui::ComponentBase
{
private:
    std::function<void()> m_QuitFunc;
    
    std::vector<std::string> m_MenuElements = {"0%", "10%", "20%", "30%", "40%", "50%", "60%", "70%", "80%", "90%"};
    std::vector<std::string> m_MenuElements2 = {"A", "B", "C", "D", "E"};
    
    ftxui::MenuOption m_MenuOption;
    ftxui::MenuOption m_MenuOption2;
    int m_MenuSelection = 0;
    int m_MenuSelection2 = 0;
    
    ftxui::Component m_Menu;
    ftxui::Component m_Menu2;
    
    ftxui::Component m_Frame;
    ftxui::Component m_MenuView;
    
    int m_SplitLeftSize = 20;
    int m_SplitLeftSize2 = 20;
    ftxui::Component m_Split;
    
    std::string longText = "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse";
    
public:
    FileManagerUI(std::function<void()> quitFunc);
    
    ftxui::Element Render() override;
    bool OnEvent(ftxui::Event event) override;
};

#endif /* FileManagerUI_h */
