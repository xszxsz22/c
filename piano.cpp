#include "piano.h"
#include "ui_piano.h"
#include <QSoundEffect>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QIcon>
#include <QDebug>
#include <QList>
#include <QPair>
#include <QTime>
#include <QTimer>
extern int high;
Piano::Piano(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::piano),
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
    soundEffectb1(new QSoundEffect(this)),
    isPause(false),
    isRecord(false),
    playbackTimer(new QTimer(this)),
    playbackIndex(0)
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
//    connect(ui->recordButton, &QPushButton::clicked, this, &Piano::on_recordButton_clicked);
//    connect(ui->playButton, &QPushButton::clicked, this, &Piano::on_playButton_clicked);
//这会导致clicked函数被引用两次
    initializeSoundEffects();
    connect(ui->voicehigh, SIGNAL(valueChanged(int)), this, SLOT(updateKeys(int)));
//    ui->A2->setAutoRepeat(true); //启用长按
//    ui->A2->setAutoRepeatDelay(400);//触发长按的时间
//    ui->A2->setAutoRepeatInterval(50);//长按时click信号间隔
//    connect(ui->A2,&QPushButton::clicked,[&]{
//       playSoundEffect(soundEffectA2, "A_2");
//    });
//由于qt的问题，长按按钮发出的声音之间仍有间隔，导致无法得到理想的结果，故取消此功能
    connect(playbackTimer, &QTimer::timeout, this, &Piano::playNextRecordedKey);
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
    recordKeyPress("A2");
    playSoundEffect(soundEffectA2, "A_2");
}

void Piano::on_A2s_clicked()
{
    recordKeyPress("A2s");
    playSoundEffect(soundEffectA2s, "A_2s");
}

void Piano::on_B2_clicked()
{
    recordKeyPress("B2");
    playSoundEffect(soundEffectB2, "B_2");
}

void Piano::on_c5_clicked()
{
    recordKeyPress("c5");
    playSoundEffect(soundEffectc5, "c5");
}

void Piano::on_c1_clicked()
{
    recordKeyPress("c1");
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
    recordKeyPress("c1s");
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
    recordKeyPress("d1");
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
    recordKeyPress("d1s");
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
    recordKeyPress("e1");
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
    recordKeyPress("f1");
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
    recordKeyPress("f1s");
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
    recordKeyPress("g1");
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
    recordKeyPress("g1s");
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
    recordKeyPress("a1");
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
    recordKeyPress("a1s");
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
    recordKeyPress("b1");
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
void Piano::updateKeys(int value)
{
    QStringList notes = generateKeyLabels(value);
    setKeyLabels(notes);
}

QStringList Piano::generateKeyLabels(int high)
{
    QStringList allNotes = {"C1", "C1s", "D1", "D1s", "E1", "F1", "F1s", "G1", "G1s", "A1", "A1s", "B1",
                            "C", "Cs", "D", "Ds", "E", "F", "Fs", "G", "Gs", "A", "As", "B",
                            "c", "cs", "d", "ds", "e", "f", "fs", "g", "gs", "a", "as", "b",
                            "c1", "c1s", "d1", "d1s", "e1", "f1", "f1s", "g1", "g1s", "a1", "a1s", "b1",
                            "c2", "c2s", "d2", "d2s", "e2", "f2", "f2s", "g2", "g2s", "a2", "a2s", "b2",
                            "c3", "c3s", "d3", "d3s", "e3", "f3", "f3s", "g3", "g3s", "a3", "a3s", "b3",
                            "c4", "c4s", "d4", "d4s", "e4", "f4", "f4s", "g4", "g4s", "a4", "a4s", "b4"};

    int startIndex = (high + 3) * 12; // calculate the starting index for the middle 12 keys
    return allNotes.mid(startIndex, 12); // return the middle 12 keys based on high value
}

void Piano::setKeyLabels(const QStringList &labels)
{
    ui->c1->setText(labels.at(0));
    ui->c1s->setText(labels.at(1));
    ui->d1->setText(labels.at(2));
    ui->d1s->setText(labels.at(3));
    ui->e1->setText(labels.at(4));
    ui->f1->setText(labels.at(5));
    ui->f1s->setText(labels.at(6));
    ui->g1->setText(labels.at(7));
    ui->g1s->setText(labels.at(8));
    ui->a1->setText(labels.at(9));
    ui->a1s->setText(labels.at(10));
    ui->b1->setText(labels.at(11));
}


void Piano::on_playButton_clicked()
{
    if (isPause) {
        ui->playButton->setStyleSheet(
            "QPushButton {"
            "border-image: url(:/picture/pause.svg);"
            "}"
        );
        // Calculate the elapsed time during the pause
        int elapsedPauseTime = pauseTime.msecsTo(QTime::currentTime());
        playbackStartTime = playbackStartTime.addMSecs(elapsedPauseTime);
        playbackTimer->start(10);
    } else {
        if (playbackTimer->isActive()) {
            ui->playButton->setStyleSheet(
                "QPushButton {"
                "border-image: url(:/picture/play.svg);"
                "}"
            );
            pauseTime = QTime::currentTime();
            playbackTimer->stop();
        } else {
            ui->playButton->setStyleSheet(
                "QPushButton {"
                "border-image: url(:/picture/pause.svg);"
                "}"
            );
            startPlayback();
        }
    }
    isPause = !isPause;
}

void Piano::on_recordButton_clicked()
{
    if (isRecord) {
        ui->recordButton->setText("录制");
    }
    else {
        recordedKeys.clear();
        recordStartTime = QTime::currentTime();
        ui->recordButton->setText("停止录制");
    }
    isRecord = !isRecord;
}
void Piano::recordKeyPress(const QString &key)
{
    if (isRecord) {
        QTime currentTime = QTime::currentTime();
        int voiceHighValue = high;
        recordedKeys.append(qMakePair(currentTime, key + ":" + QString::number(voiceHighValue)));
    }
}
void Piano::startPlayback()
{
    if (recordedKeys.isEmpty()) {
        QMessageBox::warning(this, "Warning", "No recorded keys to play.");
        stopPlayback();
        return;
    }

    isPause = true;
    playbackIndex = 0;
    playbackStartTime = QTime::currentTime();
    ui->playButton->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/picture/pause.svg);"
        "}"
    );
    playbackTimer->start(10); // Check every 10 milliseconds
}

void Piano::stopPlayback()
{
    isPause = false;
    playbackTimer->stop();
    ui->playButton->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/picture/play.svg);"
        "}"
    );
}
void Piano::playNextRecordedKey()
{
    if (playbackIndex >= recordedKeys.size()) {
        stopPlayback();
        return;
    }

    QPair<QTime, QString> keyPress = recordedKeys.at(playbackIndex);
    QTime currentTime = QTime::currentTime();
    int elapsedTime = playbackStartTime.msecsTo(currentTime);

    int keyPressTime = keyPress.first.msecsSinceStartOfDay() - recordStartTime.msecsSinceStartOfDay();
    if (elapsedTime >= keyPressTime) {
        // Extract the key and voicehigh value
        QStringList keyData = keyPress.second.split(":");
        QString key = keyData.at(0);
        int voiceHighValue = keyData.at(1).toInt();

        // Set voicehigh value
        high = voiceHighValue;

        // Play the recorded key
        if (key == "A2") playSoundEffect(soundEffectA2, "A_2");
        else if (key == "A2s") playSoundEffect(soundEffectA2s, "A_2s");
        else if (key == "B2") playSoundEffect(soundEffectB2, "B_2");
        else if (key == "c5") playSoundEffect(soundEffectc5, "c5");
        else if (key == "c1") {
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
        else if (key == "c1s"){
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
        else if (key == "d1") {
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
        else if (key == "d1s"){
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
        else if (key == "e1") {
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
        else if (key == "f1") {
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
        else if (key == "f1s") {
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
        else if (key == "g1") {
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
        else if (key == "g1s"){
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
        else if (key == "a1"){
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
        else if (key == "a1s"){
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
        else if (key == "b1"){
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

        playbackIndex++;
    }
}

void Piano::on_deleteButton_clicked()
{
    isRecord = false;
    isPause = false;
    ui->recordButton->setText("录制");
    ui->playButton->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/picture/play.svg);"
        "}"
    );

    // Stop the playback timer and reset playback index
    playbackTimer->stop();
    playbackIndex = 0;
}
