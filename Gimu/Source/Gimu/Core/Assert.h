//
// Created by Metal on 2020/11/17.
//

#ifndef GIMUDEV_ASSERT_H
#define GIMUDEV_ASSERT_H

#define GM_ASSERT(x, ...) {if(!(x)) {GM_ERROR(__VA_ARGS__); __debugbreak();}}
#define GM_CORE_ASSERT(x, ...) {if(!(x)) {GM_CORE_ERROR(__VA_ARGS__); __debugbreak();}}

#endif //GIMUDEV_ASSERT_H
