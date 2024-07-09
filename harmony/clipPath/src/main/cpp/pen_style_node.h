//
// Created on 2024/7/4.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

typedef enum {
    CLIP_PEN_STYLE_FILL = 1 << 0,
    CLIP_PEN_STYLE_STROKE = 1 << 1,
} Clip_PenStyleType;