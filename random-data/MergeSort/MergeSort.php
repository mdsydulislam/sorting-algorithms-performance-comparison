<?php
function merge($left, $right) {
    $result = [];
    $i = $j = 0;
    while ($i < count($left) && $j < count($right)) {
        if ($left[$i] < $right[$j]) {
            $result[] = $left[$i];
            $i++;
        } else {
            $result[] = $right[$j];
            $j++;
        }
    }
    while ($i < count($left)) {
        $result[] = $left[$i];
        $i++;
    }
    while ($j < count($right)) {
        $result[] = $right[$j];
        $j++;
    }
    return $result;
}
function mergeSort($arr) {
    if (count($arr) <= 1) return $arr;
    $mid = floor(count($arr) / 2);
    $left = mergeSort(array_slice($arr, 0, $mid));
    $right = mergeSort(array_slice($arr, $mid));
    return merge($left, $right);
}
$data = array_map('intval', file('random_data.txt', FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES));
$start = microtime(true);
$sortedData = mergeSort($data);
$end = microtime(true);
echo "Merge Sort Execution Time: " . number_format(($end - $start) * 1000, 4) . " milliseconds\n";