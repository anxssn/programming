#pragma once //защита от повторного включения
#include <SFML/Graphics.hpp> //графическая библиотека
#include <vector>

// Canvas dimensions (in logic pixels, before scaling)
const int WIDTH  = 800;
const int HEIGHT = 600;


const int PIXEL_SIZE = 1;

// Canvas type: 2D vector of SFML colors
using Canvas = std::vector<std::vector<sf::Color>>;

// функция
void clearCanvas(Canvas& canvas); //залить все белым
void drawPixel(Canvas& canvas, int x, int y, const sf::Color& color); //нарисовать один пиксель
void drawBrush(Canvas& canvas, int x, int y, const sf::Color& color, int radius); //нарисовать круг

//фигуры
void drawRectangle(Canvas& canvas, int x1, int y1, int x2, int y2, const sf::Color& color); //нарисовать прямоугольник
void drawLine(Canvas& canvas, int x1, int y1, int x2, int y2, const sf::Color& color); //нарисовать линию
void undo(Canvas& canvas);          // Ctrl+Z
void saveToUndo(const Canvas& canvas);   // сохранить текущее состояние 

//фильтры
void applyGrayscale(Canvas& canvas); //оттенки серого
void applyNegative(Canvas& canvas); //инвертировать цвета
void applyBlur(Canvas& canvas); //размытие изображения

// ========== Helper for display ==========
void renderToWindow(sf::RenderWindow& window, const Canvas& canvas);