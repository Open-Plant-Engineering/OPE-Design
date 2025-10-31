#include <BRepPrimAPI_MakeBox.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepTools.hxx>

int main() {
    TopoDS_Shape box = BRepPrimAPI_MakeBox(100.0, 80.0, 60.0).Shape();
    BRepTools::Write(box, "box.brep");
    return 0;
}