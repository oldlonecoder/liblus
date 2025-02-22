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
//    rem::cc terminate(rem::type reason_type) override;
protected:
    rem::cc setup_journal() override;
};

lus_app::lus_app(const std::string& app_id, lus::string::view_list cargs): lus::ui::application(app_id, cargs){}
lus_app::~lus_app(){}

rem::cc lus_app::run()
{
    lus::ui::application::run();
    terminate(rem::type::test);
    return rem::cc::terminate;
}

rem::cc lus_app::setup()
{
    return ui::application::setup();
}

rem::cc lus_app::setup_ui()
{
    return ui::application::setup_ui();
}


// rem::cc lus_app::terminate(rem::type reason_type)
// {
//     return ui::application::app().terminate(reason_type);
// }

rem::cc lus_app::setup_journal()
{
    journal::init("lus.framework.API.tests.application");
    journal::status() << rem::cc::ready << journal::eol;
    return rem::cc::ready;
}


}



auto main(int argc, char** argv, char** env) -> int
{
    std::cout << "Hello, World\n";
    lus::lus_app app{"lus_app tests", lus::string::string_view_list(argc, argv,1)};
    return static_cast<int>(app.run());
}
