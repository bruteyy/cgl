#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>

#define MAXV 50

union REGS in, out;

/* ---------- mouse functions (INT 33h) ---------- */
int initMouse(void)
{
    in.x.ax = 0;
    int86(0x33, &in, &out);
    return out.x.ax;               /* 0 = mouse not found */
}

void showMouse(void)
{
    in.x.ax = 1;
    int86(0x33, &in, &out);
}

void hideMouse(void)
{
    in.x.ax = 2;
    int86(0x33, &in, &out);
}

int getMouse(int *x, int *y)
{
    in.x.ax = 3;
    int86(0x33, &in, &out);
    *x = out.x.cx;
    *y = out.x.dx;
    return out.x.bx;               /* bit 0 = left, bit 1 = right */
}

int main()
{
    int gd = DETECT, gm;
    int vx[MAXV], vy[MAXV];        /* polygon vertices */
    float xs[MAXV], t;             /* x-crossings of one scanline */
    int n = 0, i, j, k, y, cnt;
    int ymin, ymax, btn, mx, my;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    if (!initMouse())
    {
        outtextxy(10, 10, "Mouse not found");
        getch();
        closegraph();
        return 0;
    }
    showMouse();
    outtextxy(10, 10, "Left click: add vertex    Right click: finish");

    /* ---- collect vertices with the mouse ---- */
    while (n < MAXV)
    {
        btn = getMouse(&mx, &my);

        if (btn & 2)                               /* right click */
        {
            while (getMouse(&mx, &my) & 2);        /* wait for release */
            break;
        }
        if (btn & 1)                               /* left click */
        {
            vx[n] = mx;
            vy[n] = my;
            hideMouse();
            if (n > 0)
                line(vx[n - 1], vy[n - 1], vx[n], vy[n]);
            else
                putpixel(vx[n], vy[n], WHITE);
            showMouse();
            n++;
            while (getMouse(&mx, &my) & 1);        /* wait for release */
        }
    }

    hideMouse();

    if (n < 3)
    {
        outtextxy(10, 30, "Invalid polygon");
        getch();
        closegraph();
        return 0;
    }

    /* ---- close the boundary, find ymin and ymax ---- */
    line(vx[n - 1], vy[n - 1], vx[0], vy[0]);
    ymin = ymax = vy[0];
    for (i = 1; i < n; i++)
    {
        if (vy[i] < ymin) ymin = vy[i];
        if (vy[i] > ymax) ymax = vy[i];
    }

    /* ---- scan line fill ---- */
    for (y = ymin; y <= ymax; y++)
    {
        cnt = 0;
        for (i = 0; i < n; i++)
        {
            j = (i + 1) % n;
            if (vy[i] == vy[j])                    /* ignore horizontal edges */
                continue;
            if ((vy[i] <= y && y < vy[j]) || (vy[j] <= y && y < vy[i]))
            {
                xs[cnt] = vx[i] + (float)(y - vy[i]) * (vx[j] - vx[i])
                                 / (vy[j] - vy[i]);
                cnt++;
            }
        }

        /* sort crossings in ascending order */
        for (i = 0; i < cnt - 1; i++)
            for (j = 0; j < cnt - 1 - i; j++)
                if (xs[j] > xs[j + 1])
                {
                    t = xs[j];
                    xs[j] = xs[j + 1];
                    xs[j + 1] = t;
                }

        /* pattern: bands of 4 scanlines, alternating RED and YELLOW */
        if ((y / 4) % 2 == 0)
            setcolor(RED);
        else
            setcolor(YELLOW);

        /* fill between pairs (x1,x2), (x3,x4), ... */
        for (k = 0; k + 1 < cnt; k += 2)
            line((int)xs[k], y, (int)xs[k + 1], y);
    }

    /* ---- redraw boundary on top of the fill ---- */
    setcolor(WHITE);
    for (i = 0; i < n; i++)
    {
        j = (i + 1) % n;
        line(vx[i], vy[i], vx[j], vy[j]);
    }

    getch();
    closegraph();
    return 0;
}
