#include <Logic.hpp>

#include <csignal>

#include <spdlog/spdlog.h>

void meetx::MainLoop() {
    if (!bot) {
        spdlog::get("TgBotBackend")->log(spdlog::level::err, "Something went wrong: MainLoop cannot be called without first creating a std::shared_ptr<TgBot> object");
        std::raise(SIGUSR1);
    }

    setjmp(signalsUtils::programBuf);
    auto botInfo = bot->getApi().getMe();
    spdlog::get("TgBotBackend")->log(spdlog::level::info, "Bot info:\n\tusername: {}\n\tfirst_name: {}", botInfo->username, botInfo->firstName);

    try {
        TgBot::TgLongPoll lpoll(*bot);
        while (true) {
            lpoll.start();
        }
    } catch (TgBot::TgException& apierr) {
        spdlog::get("TgBotBackend")->log(spdlog::level::err, "The bot spawned an exception: {}", apierr.what());
        std::raise(SIGUSR1);
    }
}
