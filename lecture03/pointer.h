
//lang:CwC

// Immutable
class Point {
public:
    int x_;
    int y_;

    Point() { x_ = 0; y_ = 0; }
    Point(int x, int y) : x_(x), y_(y) {}
    Point(Point* p) : x_(p->get_x()), y_(p->get_y()) {}

    // Different class types have their own deconstructors
    virtual ~Point() { }

    void move(int byx, int byy) { x_ += byx; y_ += byy;}

    int get_x() { return x_; }
    int get_y() { return y_; }
};

class ColorPoint : public Point {
public:
    String* color_; // owned - my way to remind me that colorpoint is the owener of that field
    ColorPoint() : color_(new String("White")) {}

    ~ColorPoint() { delete color_; }

};

Point* p = new ColorPoint;
delete p;