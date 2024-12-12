<?php
function heapify(&$arr, $n, $i) {
    $largest = $i;
    $left = 2 * $i + 1;
    $right = 2 * $i + 2;
    if ($left < $n && $arr[$left] > $arr[$largest]) {
        $largest = $left;
    }
    if ($right < $n && $arr[$right] > $arr[$largest]) {
        $largest = $right;
    }
    if ($largest != $i) {
        $temp = $arr[$i];
        $arr[$i] = $arr[$largest];
        $arr[$largest] = $temp;
        heapify($arr, $n, $largest);
    }
}
function heapSort($arr) {
    $n = count($arr);
    for ($i = floor($n / 2) - 1; $i >= 0; $i--) {
        heapify($arr, $n, $i);
    }
    for ($i = $n - 1; $i >= 0; $i--) {
        $temp = $arr[0];
        $arr[0] = $arr[$i];
        $arr[$i] = $temp;

        heapify($arr, $i, 0);
    }
    return $arr;
}
$data = array_map('intval', file('nearly_sorted_data.txt', FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES));
$start = microtime(true);
$sortedData = heapSort($data);
$end = microtime(true);
echo "Heap Sort Execution Time: " . number_format(($end - $start) * 1000, 4) . " milliseconds\n";