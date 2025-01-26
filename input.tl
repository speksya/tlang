fun main(): number {
    det sum: number = 0;

    for(det i: number = 0 until 100 -> i += 1) {
        sum = sum + i;
    }

    return sum;
}
