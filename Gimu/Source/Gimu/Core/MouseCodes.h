//
// Created by Metal on 2020/11/18.
//

#ifndef GIMUDEV_MOUSECODES_H
#define GIMUDEV_MOUSECODES_H

namespace Gimu {
    using MouseCode = uint16_t;

    namespace Mouse {
        enum : MouseCode {
            // From glfw3.h
            Button0 = 0,
            Button1 = 1,
            Button2 = 2,
            Button3 = 3,
            Button4 = 4,
            Button5 = 5,
            Button6 = 6,
            Button7 = 7,

            ButtonLast = Button7,
            ButtonLeft = Button0,
            ButtonRight = Button1,
            ButtonMiddle = Button2
        };
    }
}
#endif //GIMUDEV_MOUSECODES_H
