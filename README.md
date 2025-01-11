<h1 align="center">
    TF MLP Float 32 Model Deployment on ESP32-S3
</h1>

<h4 align="center">
    <a href="https://scikit-learn.org/stable/">
        <img src="https://img.shields.io/badge/scikit--learn 1.5.1-%23F7931E.svg?style=for-the-badge&logo=scikit-learn&logoColor=white"  alt="whatever"/>
    </a>
    <a href="https://www.tensorflow.org/">
        <img src="https://img.shields.io/badge/TensorFlow 2.17-FF6F00?style=for-the-badge&logo=tensorflow&logoColor=white"  alt="whatever">
    </a>
    <a href="https://keras.io/">
        <img src="https://img.shields.io/badge/Keras 3.4.1-FF0000?style=for-the-badge&logo=keras&logoColor=white"  alt="whatever">
    </a>
    <h5 align="center">
            <a href="https://en.cppreference.com/w/cpp/17">
                <img src="https://img.shields.io/badge/c++ 17-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white"  alt="whatever">
            </a>
    </h5>
</h4>

<h4 align="center">
    <div align="center">
        <hr width="250px"/>
    </div>
        <h4 align="center">Tools</h4>
        <h4 align="center">
            <a href="https://www.jetbrains.com/clion/">
                <img src="https://img.shields.io/badge/CLion 2024-000000?style=for-the-badge&logo=clion&logoColor=white"  alt="whatever">
            </a>
            <a href="https://github.com/espressif/arduino-esp32/releases/tag/3.0.7">
                <img src="https://img.shields.io/badge/Arduino Core 3.0.7-00979D?style=for-the-badge&logo=Arduino&logoColor=white"  alt="whatever">
            </a>
            <a href="https://docs.espressif.com/projects/esp-idf/en/stable/esp32s3/hw-reference/esp32s3/user-guide-devkitc-1.html">
                <img src="https://img.shields.io/badge/espressif32 s3 dev kit-E7352C.svg?style=for-the-badge&logo=espressif&logoColor=white"  alt="whatever"/>
            </a>
            <a href="https://www.tensorflow.org/lite">
                <img src="https://img.shields.io/badge/TFLITE-FF6F00?style=for-the-badge&logo=tensorflow&logoColor=white"  alt="whatever">
            </a>
            <a href="https://github.com/tensorflow/tflite-micro">
                <img src="https://img.shields.io/badge/TFLITE micro-FF6F00?style=for-the-badge&logo=tensorflow&logoColor=white"  alt="whatever">
            </a>
        </h4>
        <div align="center">
            <a href="https://platformio.org/">
                 <img src="https://img.shields.io/badge/PlatformIO-6.1.16-orange.svg"  alt="whatever">
            </a>
            <hr width="250px"/>   
        </div>
</h4>

This is a standard [platformio](https://platformio.org/) project for `esp32-s3-devkitc-1`
board which deploys a vanilla [MLP](include/optimized_mlp_float32.h) (*non quantized and utilizes author extracted features*) to ESP32-S3 chip
and collects necessary performance metrics (see [Collected Metrics](CollectedMetrics.md)).
For model training etc., please refer to
[this repository](https://github.com/arrhythmia-detection/ArrhythmiaDetectionModels).

&#160;

<div align="center">Copyright &copy; 2025-present 
     <a href="https://github.com/Inmoresentum" target="_blank">Inmoresentum</a> and Contributors
</div>

<h6 align="center">
   <a href="https://creativecommons.org/licenses/by-nc-nd/4.0/deed.en">
      <img src="https://img.shields.io/static/v1.svg?style=for-the-badge&label=License&message=CC-BY-NC-ND-4.0&colorA=FFA500&colorB=FF69B4"
         alt="whatever" style="border-radius: 5px"/>
   </a>
</h6>
