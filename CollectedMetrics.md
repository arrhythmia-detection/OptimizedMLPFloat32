### Metrics collected from ESP32 S3 DEV KIT

**Memory Total**: 512 KiB (power of 2)

**Usable Memory**: 320 KiB (power of 2)

**Flash Total**: 8 MiB  (power of 2)

**Unique Manufacturer Serial Number**: 806599A243DC

**Mac Address**: 80:65:99:A2:43:DC

#### Chapman ECG Dataset

#### Lead Two ECG Data

| Model | Accuracy (ONLINE) | Precision (ONLINE) | Execution Speed (&mu;s) | Model Arena Size (KB) | Model Size (KB) | Memory Used (KB) (Total) | Flash Size (KB) (Total) | Power consumption | Frequency (DFS OFF) |
|-------|-------------------|--------------------|-------------------------|-----------------------|-----------------|--------------------------|-------------------------|-------------------|---------------------|
| MLP   | 90%               | 90%                | 86  (avg)               | 4.700                 | 6.308           | 23.332                   | 314.449                 | 138 mW (avg)      | 240  MHz (avg)      |

**Note:** While calculating memory and flash we used power of 10 instead of power of 2.

### Per Ops Wise Execution Time

```txt
Operation FULLY_CONNECTED (number 0) executed in 33 microseconds.
Going to sleep for a half Second
Operation FULLY_CONNECTED (number 1) executed in 31 microseconds.
Going to sleep for a half Second
Operation FULLY_CONNECTED (number 2) executed in 8 microseconds.
Going to sleep for a half Second
Operation SOFTMAX (number 3) executed in 14 microseconds.
Going to sleep for a half Second
```
