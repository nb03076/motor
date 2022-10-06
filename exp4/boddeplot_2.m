Omega = [0.1 1 2 5 10 20 40 60 100];
Mag = [457 457 457 457 457 422 351.6 281.3 175.8];
phase = [-0.77 -2.121 -3.85 -7.166 -12 -24.65 -50.916 -68.618 -75.21];

figure(1);
subplot(2,1,1);
semilogx(Omega, 20*log10(Mag));
ylabel("크기(dB)");
grid on;
subplot(2,1,2);
semilogx(Omega, phase);
ylabel("위상(degree)");
xlabel("주파수(rad/s)");
grid on