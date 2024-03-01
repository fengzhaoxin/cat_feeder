#include "detection_responder.h"
#include "cat_vs_dog_model_data.h"
void RespondToDetection(tflite::ErrorReporter* error_reporter, uint8_t first_score, uint8_t second_score)
{
    if(first_score > second_score)
    {
        TF_LITE_REPORT_ERROR(error_reporter, "%s score: %d", g_cat_vs_dog_model_classes[0], first_score);
    }
    else
    {
        TF_LITE_REPORT_ERROR(error_reporter, "%s score: %d", g_cat_vs_dog_model_classes[1], second_score);
    }
}