<?php
function selectionSort($arr) {
    $n = count($arr);
    for ($i = 0; $i < $n - 1; $i++) {
        $minIdx = $i;

        for ($j = $i + 1; $j < $n; $j++) {
            if ($arr[$j] < $arr[$minIdx]) {
                $minIdx = $j;
            }
        }

        $temp = $arr[$i];
        $arr[$i] = $arr[$minIdx];
        $arr[$minIdx] = $temp;
    }
    return $arr;
}

$data = array_map('intval', file('repeated10x_10kRandomData_total100k.txt', FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES));
$start = microtime(true);
$sortedData = selectionSort($data);
$end = microtime(true);
echo "Selection Sort Execution Time: " . ($end - $start) . " seconds\n";