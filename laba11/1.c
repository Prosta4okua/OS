#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/* обробник для SIGINT */
static void signal_handler(int signo) {
    switch (signo) {
//        Interrupt
/**
 *
<dd>
<p>The <code>SIGKILL</code> signal is used to cause immediate program termination.
It cannot be handled or ignored, and is therefore always fatal.  It is
also not possible to block this signal.
</p>
<p>This signal is usually generated only by explicit request.  Since it
cannot be handled, you should generate it only as a last resort, after
first trying a less drastic method such as <kbd>C-c</kbd> or <code>SIGTERM</code>.
If a process does not respond to any other termination signals, sending
it a <code>SIGKILL</code> signal will almost always cause it to go away.
</p>
<p>In fact, if <code>SIGKILL</code> fails to terminate a process, that by itself
constitutes an operating system bug which you should report.
</p>
<p>The system will generate <code>SIGKILL</code> for a process itself under some
unusual conditions where the program cannot possibly continue to run
(even to run a signal handler).
</p></dd>
 */
        case SIGINT:
            // Usage: kill -2 PID
            fprintf(stdout, "Сигнал переривання (SIGINT) зловлено!\n");
            break;
//            Software termination
/**
 * <span id="index-termination-signal"></span>
<p>The <code>SIGTERM</code> signal is a generic signal used to cause program
termination.  Unlike <code>SIGKILL</code>, this signal can be blocked,
handled, and ignored.  It is the normal way to politely ask a program to
terminate.
</p>
<p>The shell command <code>kill</code> generates <code>SIGTERM</code> by default.
<span id="index-kill-1"></span>
</p>
 */
        case SIGTERM:
            // Usage: kill -15 PID
            fprintf(stdout, "Сигнал завершення (SIGTERM) зловлено!\n");
            break;
//            User-defined signal 1
/**
 * <dd>
<span id="index-user-signals"></span>
<p>The <code>SIGUSR1</code> and <code>SIGUSR2</code> signals are set aside for you to
use any way you want.  They’re useful for simple interprocess
communication, if you write a signal handler for them in the program
that receives the signal.
</p>
<p>There is an example showing the use of <code>SIGUSR1</code> and <code>SIGUSR2</code>
in <a href="Signaling-Another-Process.html">Signaling Another Process</a>.
</p>
<p>The default action is to terminate the process.
</p></dd>
 */
        case SIGUSR1:
            // Usage: kill -10 PID
            fprintf(stdout, "Сигнал 1, визначений користувачем (SIGUSR1), зловлено!\n");
            break;
            /**
             * <dd>
           <p>This signal typically indicates expiration of a timer that measures
           both CPU time used by the current process, and CPU time expended on
           behalf of the process by the system.  Such a timer is used to implement
           code profiling facilities, hence the name of this signal.
           </p></dd>
             */
//        case SIGPROF:
//            // Usage: kill -27 PID
//            // do nothing
//            break;
        default:
            fprintf(stderr, "Трясця, такого сигналу немає!!!");
            break;
    }
    exit(EXIT_SUCCESS);
}

//— 4 —
int main(void) {
    int p_id;

    p_id = getpid(); /*process id*/

    printf("Process ID: %d\n", p_id);

/**
 * Термінал надсилає його до процесу переднього плану, коли користувач натискає ctrl-c. Типовою поведінкою є завершення процесу, але його можна перехопити або проігнорувати. Намір полягає в тому, щоб забезпечити механізм для впорядкованого, акуратного вимкнення.
 */
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        fprintf(stderr, "Неможливо обробити SIGINT!\n");
        exit(EXIT_FAILURE);
    }

    // ввічливий вихід
    if (signal(SIGTERM, signal_handler) == SIG_ERR) {
        fprintf(stderr, "Неможливо обробити SIGTERM!\n");
        exit(EXIT_FAILURE);
    }

    if (signal(SIGPROF, SIGPROF) == SIG_ERR) {
        fprintf(stderr, "Неможливо скинути SIGPROF!\n");
        exit(EXIT_FAILURE);
    }

    if (signal(SIGUSR1, signal_handler) == SIG_ERR) {
        fprintf(stderr, "Неможливо ігнорувати SIGUSR1!\n");
        exit(EXIT_FAILURE);
    }

    for (;;)
        pause();
    return 0;
}