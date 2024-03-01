#include "../image_provider.h"
#include "../cat_vs_dog_model_data.h"
#include "string.h"
#include "esp_log.h"
// #include "esp_camera.h"
#include "app_camera_esp.h"

static const char *TAG = "example:take_picture";

TfLiteStatus GetImage(tflite::ErrorReporter* error_reporter, int image_width, int image_height, int channels, uint8_t* image_data)
{
    camera_fb_t *fb = esp_camera_fb_get();
    if (!fb) {
        ESP_LOGE(TAG, "Camera capture failed");
        return kTfLiteError;
    }
    if (fb->width != image_width || fb->height != image_height) {
        ESP_LOGE(TAG, "Image size mismatch");
        esp_camera_fb_return(fb);
        return kTfLiteError;
    }
    if (channels != kNumChannels) {
        ESP_LOGE(TAG, "Invalid number of channels");
        esp_camera_fb_return(fb);
        return kTfLiteError;
    }
    fmt2rgb888(fb->buf, fb->len, CAMERA_PIXEL_FORMAT, image_data);
    // memcpy(image_data, fb->buf, fb->len);
    esp_camera_fb_return(fb);
    return kTfLiteOk;
}