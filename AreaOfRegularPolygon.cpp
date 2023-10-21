double DegreeToRad(double angle) {
    return angle * PI / 180.0;
}
double AreaOfRegularPoly(int n, double x) {
    return (n * x * x) / (4 * tan(DegreeToRad(180.0 / n)));
}
