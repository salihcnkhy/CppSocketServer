//
// Created by Salihcan Kahya on 17.10.2020.
//

#ifndef Variables_H
#define Variables_H

namespace Variables{
    #include "Vectors/Vector3.h"
    class Vector3Int : BaseClass::Vector3<int>{
    public:
        Vector3Int(int x, int y, int z);
    };
    class Vector3Float : BaseClass::Vector3<float>{};
    class Vector3Double : BaseClass::Vector3<double>{};
}
#endif //Variables_H
