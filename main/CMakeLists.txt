
#
# Main component of TF Micro project 'doorbell_camera'.
#

idf_component_register(
    SRCS detection_responder.cc esp/image_provider.cc esp/main.cc main_functions.cc cat_vs_dog_model_data.cpp esp/app_camera_esp.c
    INCLUDE_DIRS "")
    # model_settings.cc