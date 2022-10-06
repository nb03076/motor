clear

K = 455.1;

tau = 0.027;

sys = tf(K,[tau 1]);

bode(sys);

xlim([0.1 100]);
grid on