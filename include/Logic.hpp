#pragma once

#include <csetjmp>

#include <pqxx/pqxx>
#include <tgbot/tgbot.h>

namespace db {
    extern std::shared_ptr<pqxx::connection> database;
}

namespace signalsUtils {
    extern sigjmp_buf programBuf;
}

namespace meetx {
    extern std::shared_ptr<TgBot::Bot> bot;
    void MeetXStart(const std::string& token = "");
    void MainLoop();
}
