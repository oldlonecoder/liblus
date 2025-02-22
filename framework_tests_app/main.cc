#include <lus/journal.h>
#include <lus/ui/application.h>


namespace lus
{

class lus_app : public ui::application
{
public:
    lus_app() = default;
    lus_app(const std::string& app_id, lus::string::view_list cargs);
    ~lus_app() override;

    rem::cc run() override;
    rem::cc setup() override;
    rem::cc setup_ui() override;

};

lus_app::lus_app(const std::string& app_id, lus::string::view_list cargs): lus::ui::application(app_id, cargs){}
lus_app::~lus_app(){}

rem::cc lus_app::run()
{
    return lus::ui::application::run();
}

rem::cc lus_app::setup()
{
    return ui::application::setup();
}

rem::cc lus_app::setup_ui()
{
    return ui::application::setup_ui();
}

}



auto main(int argc, char** argv, char** env) -> int
{
    std::cout << "Hello, World\n";
    return 0;
}
