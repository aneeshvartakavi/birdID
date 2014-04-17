/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#ifndef BINARYDATA_H_46640364_INCLUDED
#define BINARYDATA_H_46640364_INCLUDED

namespace BinaryData
{
    extern const char*   svmTrain_model;
    const int            svmTrain_modelSize = 1579831;

    extern const char*   min_txt;
    const int            min_txtSize = 520;

    extern const char*   range_txt;
    const int            range_txtSize = 829;

    extern const char*   svm_def;
    const int            svm_defSize = 477;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Number of elements in the namedResourceList array.
    const int namedResourceListSize = 4;

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes) throw();
}

#endif
