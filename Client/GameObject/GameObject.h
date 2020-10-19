//
// Created by Salihcan Kahya on 17.10.2020.
//

#ifndef GameObject_H
#define GameObject_H

#include "../../Helpers/Variables/Variable.h"

namespace SocketClient {

    class GameObject {
    private:
#pragma region Transform
        Variables::Vector3<float> position = Variables::Vector3<float>(0, 0,0);
        Variables::Vector3<float> rotation = Variables::Vector3<float>(0, 0,0);
#pragma endregion Transform
    public:
        GameObject();
    };
}


#endif //GameObject_H
