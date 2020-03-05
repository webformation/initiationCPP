int thermometre(int num, int code)
{
    switch(code)
    {
    case 0: // initialisation
        return 0;
    case 1: // fin
        return 0;
    case 2: // acquisiation
        return 20;
    }
    return -1;
}
