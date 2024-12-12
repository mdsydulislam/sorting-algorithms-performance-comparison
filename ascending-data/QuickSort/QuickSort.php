<?php
function quickSort($arr) {
    if (count($arr) < 2) return $arr;
    $pivot = $arr[0];
    $left = array_filter(array_slice($arr, 1), fn($x) => $x <= $pivot);
    $right = array_filter(array_slice($arr, 1), fn($x) => $x > $pivot);
    return array_merge(quickSort($left), [$pivot], quickSort($right));
}
$data = array_map('intval', file('ascending_data.txt', FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES));
$start = microtime(true);
$sortedData = quickSort($data);
$end = microtime(true);
echo "Quick Sort Execution Time: " . number_format(($end - $start) * 1000, 4) . " milliseconds\n";