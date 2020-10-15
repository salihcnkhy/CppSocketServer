//
// Created by Salihcan Kahya on 15.10.2020.
//

#ifndef ErrorCode_H
#define ErrorCode_H
namespace Error{
    enum Code{
        EstablishConnection = 5,
        BindServer = 6,
        ListenServer = 7,
        ServerIsFull = 8,
    };
}
#endif //ErrorCode_H
