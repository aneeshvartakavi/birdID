/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== svm.def ==================
static const unsigned char temp_binary_data_0[] =
"LIBRARY libsvm\n"
"EXPORTS\n"
"\tsvm_train\t@1\n"
"\tsvm_cross_validation\t@2\n"
"\tsvm_save_model\t@3\n"
"\tsvm_load_model\t@4\n"
"\tsvm_get_svm_type\t@5\n"
"\tsvm_get_nr_class\t@6\n"
"\tsvm_get_labels\t@7\n"
"\tsvm_get_svr_probability\t@8\n"
"\tsvm_predict_values\t@9\n"
"\tsvm_predict\t@10\n"
"\tsvm_predict_probability\t@11\n"
"\tsvm_free_model_content\t@12\n"
"\tsvm_free_and_destroy_model\t@13\n"
"\tsvm_destroy_param\t@14\n"
"\tsvm_check_parameter\t@15\n"
"\tsvm_check_probability_model\t@16\n"
"\tsvm_set_print_string_function\t@17\n"
"\tsvm_get_sv_indices\t@18\n"
"\tsvm_get_nr_sv\t@19\n";

const char* svm_def = (const char*) temp_binary_data_0;


const char* getNamedResource (const char*, int&) throw();
const char* getNamedResource (const char* resourceNameUTF8, int& numBytes) throw()
{
    unsigned int hash = 0;
    if (resourceNameUTF8 != 0)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0x92f52cb0:  numBytes = 477; return svm_def;
        default: break;
    }

    numBytes = 0;
    return 0;
}

const char* namedResourceList[] =
{
    "svm_def"
};

}
