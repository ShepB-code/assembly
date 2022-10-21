const int MAX = 256;


int main() {
    int total;
    int i = 0;
    double percentE;

    cout << "This program will verify that E/e's occur apporixmately 10%";

    cin.get(textLine, 255);
    total = strlen(textLine);
    asmCountE();

    percentE = (double(numE) / double(total)) * 100.0;
}

void __declspec(naked) asmCountE()
{
    __asm
    {
        START: lea ebx, textLine;
            sub eax, eax
        TOP2: mov dl, [ebx]
              cmp dl, '\0'
              je DONE
              cmp dl, 'e'
              je COUNT
              dmp dl, 'E'
        COUNT: inc eax
        NEXT: inc ebx
        jmp TOP2

        DONE: mov numE, eax

    }
}