#include "Canvas.cpp"

int main()
{
    Canvas canvas(38, 100);
    canvas.FillCircle(10, 10, 4, 'H');
    canvas.FillRect(20, 20, 30, 30, 'M');
    canvas.DrawCircle(6, 30, 5, '*');
    canvas.DrawRect(45, 6, 67, 12, 'R');
    canvas.FillRect(50, 8, 62, 10, 'F');
    canvas.SetPoint(1, 1, 'S');
    canvas.DrawLine(23, 50, 28, 58, '$');
    canvas.Print();
}
