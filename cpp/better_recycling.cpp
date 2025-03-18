#include "better_recycling.h"
#include "commands.h"

void better_recycle(std::vector<Command *> &commands) {
    for (auto cmd: commands) {
        cmd->execute();
    }
}
