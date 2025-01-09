### Metrics collected from ESP32 S3 DEV KIT

**Memory Total**: 512 KiB (power of 2)

**Usable Memory**: 320 KiB (power of 2)

**Flash Total**: 8 MiB  (power of 2)

**Unique Manufacturer Serial Number**: 806599A243DC

**Mac Address**: 80:65:99:A2:43:DC

#### CAPPIMU Dataset

#### IMU Sensor Position: Right Wrist

##### Two seconds sliding window One Second Overlap

| Model | Accuracy (OFFLINE) | Precision (OFFLINE) | Execution Speed (&mu;s) | Model Arena Size (KB) | Model Size (KB) | Memory Used (KB) (Total) | Flash Size (KB) (Total) | Power consumption | Frequency (DFS OFF) |
|-------|--------------------|---------------------|-------------------------|-----------------------|-----------------|--------------------------|-------------------------|-------------------|---------------------|
| MLP   | 90%                | 90%                 | 20405   (avg)           | 5.700                 | 508.140         | 27.988                   | 820.265                 | 235 mW (avg)      | 240  MHz (avg)      |

**Note:** While calculating memory and flash we used power of 10 instead of power of 2.

### Per Ops Wise Execution Time

```txt
Operation FULLY_CONNECTED (number 0) executed in 18548 microseconds.
Going to sleep for a half Second
Operation FULLY_CONNECTED (number 1) executed in 1345 microseconds.
Going to sleep for a half Second
Operation FULLY_CONNECTED (number 2) executed in 344 microseconds.
Going to sleep for a half Second
Operation FULLY_CONNECTED (number 3) executed in 123 microseconds.
Going to sleep for a half Second
Operation SOFTMAX (number 4) executed in 45 microseconds.
Going to sleep for a half Second
expected class 20, predicted class 19
```
