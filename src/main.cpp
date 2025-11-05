#include <BRepPrimAPI_MakeBox.hxx>
#include <STEPControl_Writer.hxx>
#include <Interface_Static.hxx>
#include <TopoDS_Shape.hxx>

int main() {
    // Create a simple box shape
    TopoDS_Shape box = BRepPrimAPI_MakeBox(100.0, 50.0, 30.0).Shape();

    // Initialize the STEP writer
    STEPControl_Writer writer;
    Interface_Static::SetCVal("write.step.schema", "AP203"); // or "AP214"

    // Transfer the shape to the writer
    IFSelect_ReturnStatus status = writer.Transfer(box, STEPControl_AsIs);
    if (status != IFSelect_RetDone) {
        std::cerr << "Error: Failed to transfer shape to STEP writer." << std::endl;
        return 1;
    }

    // Write the STEP file
    status = writer.Write("C:/db/box_output.stp");
    if (status != IFSelect_RetDone) {
        std::cerr << "Error: Failed to write STEP file." << std::endl;
        return 1;
    }

    std::cout << "STEP file successfully written to 'box_output.stp'" << std::endl;
    return 0;
}