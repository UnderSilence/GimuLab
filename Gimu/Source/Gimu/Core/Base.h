//
// Created by Metal on 2020/11/15.
//

#ifndef GIMU_BASE_H
#define GIMU_BASE_H

#define BIT(x) (1U<<x)

#include "Gimu/Core/PlatformDetection.h"

namespace Gimu {

    template<typename T>
    using Scope = std::unique_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Ref = std::shared_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

}

#include "Gimu/Core/Application.h"
#include "Gimu/Core/Log.h"
#include "Gimu/Core/Assert.h"

#endif //GIMU_BASE_H
