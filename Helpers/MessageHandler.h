//
// Created by Salihcan Kahya on 15.10.2020.
//

#ifndef MessageHandler_H
#define MessageHandler_H

namespace Helper{
    class MessageHandler {
    public:
        virtual void Execute() = 0;
    };

    class PlayerMovementHandler : MessageHandler {
        void Execute() override;
    };
    class PlayerRotationHandler : MessageHandler {
        void Execute() override;
    };
    class PLayerAnimationHandler : MessageHandler {
        void Execute() override;
    };

}



#endif //MessageHandler_H
