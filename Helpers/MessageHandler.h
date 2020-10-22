//
// Created by Salihcan Kahya on 15.10.2020.
//

#ifndef MessageHandler_H
#define MessageHandler_H
#include <iostream>

namespace Helper{
    class MessageHandler {
    private:
        std::string message;
    public:
        MessageHandler(std::string message) : message(message) {}
        virtual void Execute() = 0;
    };

    class PlayerMovementHandler : MessageHandler {
    public:
        void Execute() override;
        PlayerMovementHandler(std::string message) : MessageHandler(message) {}

    };
    class PlayerRotationHandler : MessageHandler {
        void Execute() override;
    };
    class PLayerAnimationHandler : MessageHandler {
        void Execute() override;
    };

}



#endif //MessageHandler_H
