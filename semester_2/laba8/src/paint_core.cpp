#include "paint_core.hpp"
#include <algorithm>   // std::min, std::max, std::transform, std::fill
#include <cmath>       // std::abs
#include <stack>       // std::stack

extern std::stack<Canvas> undoStack;

//функция сохранения
void saveToUndo(const Canvas& canvas) {
    undoStack.push(canvas);
}

// Очистка холста 
void clearCanvas(Canvas& canvas) {
    for (auto& row : canvas){
        std::fill(row.begin(),row.end(), sf::Color::White);
    }
    // TODO: заполнить весь холст белым цветом sf::Color::White
    // Использовать std::fill для каждой строки (или двойной цикл)
    // Подсказка: for (auto& row : canvas) std::fill(row.begin(), row.end(), sf::Color::White);
}

// Рисование пикселя 
void drawPixel(Canvas& canvas, int x, int y, const sf::Color& color) {
    // TODO: проверить, что x и y в пределах [0, WIDTH-1] и [0, HEIGHT-1]
    // Если да, то присвоить canvas[y][x] = color
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT){
        canvas[y][x] = color;
    } 
}

// Круглая кисть 
void drawBrush(Canvas& canvas, int x, int y, const sf::Color& color, int radius) {
    // TODO: закрасить круг с центром (x,y) радиусом radius
    // Перебрать все dx, dy от -radius до +radius, проверить dx*dx+dy*dy <= radius*radius
    // Вызвать drawPixel для (x+dx, y+dy)
    for (int dy = -radius; dy <= radius; dy++){
        for (int dx = -radius; dx <= radius; dx++){
            if (dx*dx+dy*dy <= radius*radius){
                drawPixel(canvas, x+dx, y+dy, color);
            }
        }
    }
}

//  Прямоугольник 
void drawRectangle(Canvas& canvas, int x1, int y1, int x2, int y2, const sf::Color& color) {
    saveToUndo(canvas);   // уже есть, не удалять
    // TODO: вычислить left = min(x1,x2), right = max(x1,x2), top = min(y1,y2), bottom = max(y1,y2)
    // Двойной цикл for (int y = top; y <= bottom; ++y) for (int x = left; x <= right; ++x)
    // Вызвать drawPixel(canvas, x, y, color)
    int left = std::min(x1,x2);
    int right = std::max(x1,x2);
    int top = std::min(y1,y2);
    int bottom = std::max(y1,y2);
    for (int y = top; y <= bottom; ++y){
        for (int x = left; x <= right; ++x){
            drawPixel(canvas,x,y,color);
        }
    }
}

 // Линия (Брезенхем) 
void drawLine(Canvas& canvas, int x1, int y1, int x2, int y2, const sf::Color& color) {
    saveToUndo(canvas);
    int dx = std::abs(x2-x1);
    int dy = std::abs(y2-y1);
    int sx = (x1<x2)? 1:-1;
    int sy = (y1<y2)? 1:-1;
    int err = dx-dy;
    while(true){
        drawPixel(canvas,x1,y1,color);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2*err;
        if (e2>-dy){
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx){
            err += dx;
            y1 += sy;
        }
    } 
    // TODO: реализовать целочисленный алгоритм Брезенхема
    // Использовать std::abs, переменные dx, dy, sx, sy, err
    // В цикле рисовать пиксель и изменять x1,y1 пока не дойдём до (x2,y2)
}

//  Undo 
void undo(Canvas& canvas) {
    if (!undoStack.empty()){
        canvas = undoStack.top();
        undoStack.pop();
    }
    // TODO: если undoStack не пуст, то взять верхний элемент и присвоить canvas, затем удалить его
    // иначе ничего не делать
}

// Вспомогательная отрисовка 
void renderToWindow(sf::RenderWindow& window, const Canvas& canvas) {
    static sf::Image image;
    static sf::Texture texture;
    static sf::Sprite sprite;
    
    image.create(WIDTH, HEIGHT);
    for (int y = 0; y < HEIGHT; ++y)
        for (int x = 0; x < WIDTH; ++x)
            image.setPixel(x, y, canvas[y][x]);
    
    texture.loadFromImage(image);
    texture.setSmooth(false);
    sprite.setTexture(texture);
    sprite.setScale(PIXEL_SIZE, PIXEL_SIZE);
    window.draw(sprite);
}