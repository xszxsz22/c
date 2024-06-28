#include "piano.h"
#include "ui_piano.h"
#include <QSoundEffect>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QMessageBox>

extern int high;

Piano::Piano(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Piano),
    soundEffectA2(new QSoundEffect(this)),
    soundEffectA2s(new QSoundEffect(this)),
    soundEffectB2(new QSoundEffect(this)),
    soundEffectc5(new QSoundEffect(this)),
    soundEffectC(new QSoundEffect(this)),
    soundEffectCs(new QSoundEffect(this)),
    soundEffectD(new QSoundEffect(this)),
    soundEffectDs(new QSoundEffect(this)),
    soundEffectE(new QSoundEffect(this)),
    soundEffectF(new QSoundEffect(this)),
    soundEffectFs(new QSoundEffect(this)),
    soundEffectG(new QSoundEffect(this)),
    soundEffectGs(new QSoundEffect(this)),
    soundEffectA(new QSoundEffect(this)),
    soundEffectAs(new QSoundEffect(this)),
    soundEffectB(new QSoundEffect(this)),
    soundEffectc(new QSoundEffect(this)),
    soundEffectcs(new QSoundEffect(this)),
    soundEffectd(new QSoundEffect(this)),
    soundEffectds(new QSoundEffect(this)),
    soundEffecte(new QSoundEffect(this)),
    soundEffectf(new QSoundEffect(this)),
    soundEffectfs(new QSoundEffect(this)),
    soundEffectg(new QSoundEffect(this)),
    soundEffectgs(new QSoundEffect(this)),
    soundEffecta(new QSoundEffect(this)),
    soundEffectas(new QSoundEffect(this)),
    soundEffectb(new QSoundEffect(this)),
    soundEffectc1(new QSoundEffect(this)),
    soundEffectc1s(new QSoundEffect(this)),
    soundEffectd1(new QSoundEffect(this)),
    soundEffectd1s(new QSoundEffect(this)),
    soundEffecte1(new QSoundEffect(this)),
    soundEffectf1(new QSoundEffect(this)),
    soundEffectf1s(new QSoundEffect(this)),
    soundEffectg1(new QSoundEffect(this)),
    soundEffectg1s(new QSoundEffect(this)),
    soundEffecta1(new QSoundEffect(this)),
    soundEffecta1s(new QSoundEffect(this)),
    soundEffectb1(new QSoundEffect(this))
{
    ui->setupUi(this);

    connect(ui->A2, &QPushButton::clicked, this, &Piano::on_A2_clicked);
    connect(ui->A2s, &QPushButton::clicked, this, &Piano::on_A2s_clicked);
    connect(ui->B2, &QPushButton::clicked, this, &Piano::on_B2_clicked);
    connect(ui->c5, &QPushButton::clicked, this, &Piano::on_c5_clicked);

    connect(ui->c1, &QPushButton::clicked, this, &Piano::on_c1_clicked);
    connect(ui->c1s, &QPushButton::clicked, this, &Piano::on_c1s_clicked);
    connect(ui->d1, &QPushButton::clicked, this, &Piano::on_d1_clicked);
    connect(ui->d1s, &QPushButton::clicked, this, &Piano::on_d1s_clicked);
    connect(ui->e1, &QPushButton::clicked, this, &Piano::on_e1_clicked);
    connect(ui->f1, &QPushButton::clicked, this, &Piano::on_f1_clicked);
    connect(ui->f1s, &QPushButton::clicked, this, &Piano::on_f1s_clicked);
    connect(ui->g1, &QPushButton::clicked, this, &Piano::on_g1_clicked);
    connect(ui->g1s, &QPushButton::clicked, this, &Piano::on_g1s_clicked);
    connect(ui->a1, &QPushButton::clicked, this, &Piano::on_a1_clicked);
    connect(ui->a1s, &QPushButton::clicked, this, &Piano::on_a1s_clicked);
    connect(ui->b1, &QPushButton::clicked, this, &Piano::on_b1_clicked);
    connect(ui->voicehigh, QOverload<int>::of(&QSpinBox::valueChanged), this, &Piano::on_voicehigh_valueChanged);

    initializeSoundEffects();
}

Piano::~Piano()
{
    delete ui;
}

void Piano::initializeSoundEffects()
{
    soundEffectA2->setSource(QUrl("qrc:/note/A_2.wav"));
    soundEffectA2s->setSource(QUrl("qrc:/note/A_2s.wav"));
    soundEffectB2->setSource(QUrl("qrc:/note/B_2.wav"));
    soundEffectc5->setSource(QUrl("qrc:/note/c5.wav"));

    soundEffectC->setSource(QUrl("qrc:/note/C.wav"));
    soundEffectCs->setSource(QUrl("qrc:/note/Cs.wav"));
    soundEffectD->setSource(QUrl("qrc:/note/D.wav"));
    soundEffectDs->setSource(QUrl("qrc:/note/Ds.wav"));
    soundEffectE->setSource(QUrl("qrc:/note/E.wav"));
    soundEffectF->setSource(QUrl("qrc:/note/F.wav"));
    soundEffectFs->setSource(QUrl("qrc:/note/Fs.wav"));
    soundEffectG->setSource(QUrl("qrc:/note/G.wav"));
    soundEffectGs->setSource(QUrl("qrc:/note/Gs.wav"));
    soundEffectA->setSource(QUrl("qrc:/note/A.wav"));
    soundEffectAs->setSource(QUrl("qrc:/note/As.wav"));
    soundEffectB->setSource(QUrl("qrc:/note/B.wav"));

    soundEffectc->setSource(QUrl("qrc:/note/cc.wav"));
    soundEffectcs->setSource(QUrl("qrc:/note/ccs.wav"));
    soundEffectd->setSource(QUrl("qrc:/note/dd.wav"));
    soundEffectds->setSource(QUrl("qrc:/note/dds.wav"));
    soundEffecte->setSource(QUrl("qrc:/note/ee.wav"));
    soundEffectf->setSource(QUrl("qrc:/note/ff.wav"));
    soundEffectfs->setSource(QUrl("qrc:/note/ffs.wav"));
    soundEffectg->setSource(QUrl("qrc:/note/gg.wav"));
    soundEffectgs->setSource(QUrl("qrc:/note/ggs.wav"));
    soundEffecta->setSource(QUrl("qrc:/note/aa.wav"));
    soundEffectas->setSource(QUrl("qrc:/note/aas.wav"));
    soundEffectb->setSource(QUrl("qrc:/note/bb.wav"));

    soundEffectc1->setSource(QUrl("qrc:/note/c1.wav"));
    soundEffectc1s->setSource(QUrl("qrc:/note/c1s.wav"));
    soundEffectd1->setSource(QUrl("qrc:/note/d1.wav"));
    soundEffectd1s->setSource(QUrl("qrc:/note/d1s.wav"));
    soundEffecte1->setSource(QUrl("qrc:/note/e1.wav"));
    soundEffectf1->setSource(QUrl("qrc:/note/f1.wav"));
    soundEffectf1s->setSource(QUrl("qrc:/note/f1s.wav"));
    soundEffectg1->setSource(QUrl("qrc:/note/g1.wav"));
    soundEffectg1s->setSource(QUrl("qrc:/note/g1s.wav"));
    soundEffecta1->setSource(QUrl("qrc:/note/a1.wav"));
    soundEffecta1s->setSource(QUrl("qrc:/note/a1s.wav"));
    soundEffectb1->setSource(QUrl("qrc:/note/b1.wav"));
}

void Piano::playSoundEffect(QSoundEffect *soundEffect, const QString &baseName)
{
    soundEffect->setSource(QUrl("qrc:/note/" + baseName + ".wav"));
    soundEffect->play();
}

void Piano::on_A2_clicked()
{
    playSoundEffect(soundEffectA2, "A_2");
}

void Piano::on_A2s_clicked()
{
    playSoundEffect(soundEffectA2s, "A_2s");
}

void Piano::on_B2_clicked()
{
    playSoundEffect(soundEffectB2, "B_2");
}

void Piano::on_c5_clicked()
{
    playSoundEffect(soundEffectc5, "c5");
}

void Piano::on_c1_clicked()
{
    if (high == -3)
        playSoundEffect(soundEffectC, "C_1");
    else if (high == -2)
        playSoundEffect(soundEffectC, "C");
    else if (high == -1)
        playSoundEffect(soundEffectC, "cc");
    else if (high == 0)
        playSoundEffect(soundEffectC, "c1");
    else if (high == 1)
        playSoundEffect(soundEffectC, "c2");
    else if (high == 2)
        playSoundEffect(soundEffectC, "c3");
    else if (high == 3)
        playSoundEffect(soundEffectC, "c4");
}

void Piano::on_c1s_clicked()
{
    if (high == -3)
        playSoundEffect(soundEffectCs, "C_1s");
    else if (high == -2)
        playSoundEffect(soundEffectCs, "Cs");
    else if (high == -1)
        playSoundEffect(soundEffectCs, "ccs");
    else if (high == 0)
        playSoundEffect(soundEffectCs, "c1s");
    else if (high == 1)
        playSoundEffect(soundEffectCs, "c2s");
    else if (high == 2)
        playSoundEffect(soundEffectCs, "c3s");
    else if (high == 3)
        playSoundEffect(soundEffectCs, "c4s");
}

void Piano::on_d1_clicked()
{
    if (high == -3)
        playSoundEffect(soundEffectD, "D_1");
    else if (high == -2)
        playSoundEffect(soundEffectD, "D");
    else if (high == -1)
        playSoundEffect(soundEffectD, "dd");
    else if (high == 0)
        playSoundEffect(soundEffectD, "d1");
    else if (high == 1)
        playSoundEffect(soundEffectD, "d2");
    else if (high == 2)
        playSoundEffect(soundEffectD, "d3");
    else if (high == 3)
        playSoundEffect(soundEffectD, "d4");
}

void Piano::on_d1s_clicked()
{
    if (high == -3)
        playSoundEffect(soundEffectDs, "D_1s");
    else if (high == -2)
        playSoundEffect(soundEffectDs, "Ds");
    else if (high == -1)
        playSoundEffect(soundEffectDs, "dds");
    else if (high == 0)
        playSoundEffect(soundEffectDs, "d1s");
    else if (high == 1)
        playSoundEffect(soundEffectDs, "d2s");
    else if (high == 2)
        playSoundEffect(soundEffectDs, "d3s");
    else if (high == 3)
        playSoundEffect(soundEffectDs, "d4s");
}

void Piano::on_e1_clicked()
{
    if (high == -3)
        playSoundEffect(soundEffectE, "E_1");
    else if (high == -2)
        playSoundEffect(soundEffectE, "E");
    else if (high == -1)
        playSoundEffect(soundEffectE, "ee");
    else if (high == 0)
        playSoundEffect(soundEffectE, "e1");
    else if (high == 1)
        playSoundEffect(soundEffectE, "e2");
    else if (high == 2)
        playSoundEffect(soundEffectE, "e3");
    else if (high == 3)
        playSoundEffect(soundEffectE, "e4");
}

void Piano::on_f1_clicked()
{
    if (high == -3)
        playSoundEffect(soundEffectF, "F_1");
    else if (high == -2)
        playSoundEffect(soundEffectF, "F");
    else if (high == -1)
        playSoundEffect(soundEffectF, "ff");
    else if (high == 0)
        playSoundEffect(soundEffectF, "f1");
    else if (high == 1)
        playSoundEffect(soundEffectF, "f2");
    else if (high == 2)
        playSoundEffect(soundEffectF, "f3");
    else if (high == 3)
        playSoundEffect(soundEffectF, "f4");
}

void Piano::on_f1s_clicked()
{
    if (high == -3)
        playSoundEffect(soundEffectFs, "F_1s");
    else if (high == -2)
        playSoundEffect(soundEffectFs, "Fs");
    else if (high == -1)
        playSoundEffect(soundEffectFs, "ffs");
    else if (high == 0)
        playSoundEffect(soundEffectFs, "f1s");
    else if (high == 1)
        playSoundEffect(soundEffectFs, "f2s");
    else if (high == 2)
        playSoundEffect(soundEffectFs, "f3s");
    else if (high == 3)
        playSoundEffect(soundEffectFs, "f4s");
}

void Piano::on_g1_clicked()
{
    if (high == -3)
        playSoundEffect(soundEffectG, "G_1");
    else if (high == -2)
        playSoundEffect(soundEffectG, "G");
    else if (high == -1)
        playSoundEffect(soundEffectG, "gg");
    else if (high == 0)
        playSoundEffect(soundEffectG, "g1");
    else if (high == 1)
        playSoundEffect(soundEffectG, "g2");
    else if (high == 2)
        playSoundEffect(soundEffectG, "g3");
    else if (high == 3)
        playSoundEffect(soundEffectG, "g4");
}

void Piano::on_g1s_clicked()
{
    if (high == -3)
        playSoundEffect(soundEffectGs, "G_1s");
    else if (high == -2)
        playSoundEffect(soundEffectGs, "Gs");
    else if (high == -1)
        playSoundEffect(soundEffectGs, "ggs");
    else if (high == 0)
        playSoundEffect(soundEffectGs, "g1s");
    else if (high == 1)
        playSoundEffect(soundEffectGs, "g2s");
    else if (high == 2)
        playSoundEffect(soundEffectGs, "g3s");
    else if (high == 3)
        playSoundEffect(soundEffectGs, "g4s");
}

void Piano::on_a1_clicked()
{
    if (high == -3)
        playSoundEffect(soundEffectA, "A_1");
    else if (high == -2)
        playSoundEffect(soundEffectA, "A");
    else if (high == -1)
        playSoundEffect(soundEffectA, "aa");
    else if (high == 0)
        playSoundEffect(soundEffectA, "a1");
    else if (high == 1)
        playSoundEffect(soundEffectA, "a2");
    else if (high == 2)
        playSoundEffect(soundEffectA, "a3");
    else if (high == 3)
        playSoundEffect(soundEffectA, "a4");
}

void Piano::on_a1s_clicked()
{
    if (high == -3)
        playSoundEffect(soundEffectAs, "A_1s");
    else if (high == -2)
        playSoundEffect(soundEffectAs, "As");
    else if (high == -1)
        playSoundEffect(soundEffectAs, "aas");
    else if (high == 0)
        playSoundEffect(soundEffectAs, "a1s");
    else if (high == 1)
        playSoundEffect(soundEffectAs, "a2s");
    else if (high == 2)
        playSoundEffect(soundEffectAs, "a3s");
    else if (high == 3)
        playSoundEffect(soundEffectAs, "a4s");
}

void Piano::on_b1_clicked()
{
    if (high == -3)
        playSoundEffect(soundEffectB, "B_1");
    else if (high == -2)
        playSoundEffect(soundEffectB, "B");
    else if (high == -1)
        playSoundEffect(soundEffectB, "bb");
    else if (high == 0)
        playSoundEffect(soundEffectB, "b1");
    else if (high == 1)
        playSoundEffect(soundEffectB, "b2");
    else if (high == 2)
        playSoundEffect(soundEffectB, "b3");
    else if (high == 3)
        playSoundEffect(soundEffectB, "b4");
}

void Piano::on_voicehigh_valueChanged(int arg1)
{
    high = arg1;
}
