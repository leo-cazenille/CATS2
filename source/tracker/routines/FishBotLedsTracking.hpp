#ifndef CATS2_FISHBOT_LEDS_TRACKING_HPP
#define CATS2_FISHBOT_LEDS_TRACKING_HPP

#include "TrackingRoutine.hpp"
#include "settings/FishBotLedsTrackingSettings.hpp"
#include "TrackerPointerTypes.hpp"

/*!
 * Tracks the leds that are placed on the bottom of the FishBots. Basically it looks for the blobs of
 * the given color, select two biggest and then gets the robots position and orientation based on these
 * two blobs.
 */
class FishBotLedsTracking  : public TrackingRoutine
{
    Q_OBJECT

public:
    //! Constructor. Gets the settings, the input queue to process and a queue to place debug images on request.
    explicit FishBotLedsTracking(TrackingRoutineSettingsPtr settings, TimestampedFrameQueuePtr inputQueue, TimestampedFrameQueuePtr debugQueue);
    //! Destructor.
    virtual ~FishBotLedsTracking();

    //! Reports on what type of agent can be tracked by this routine.
    virtual QList<AgentType> capabilities() const override;

protected:
    //! The tracking routine excecuted. Gets the original frame, detects
    //! agents, eventually associates them with the trajectories and
    //! enqueue debug images on request. Overriden from TrackingRoutine.
    virtual void doTracking(const TimestampedFrame& frame) override;

private:
    //! The tracking settings.
    FishBotLedsTrackingSettingsData m_settings;
    //! Searches for the given robot's leds on the image.
    void detectLeds(size_t robotIndex);

private:
    //! The intermediate data.
    //! The binary mask image.
    cv::Mat m_maskImage;
    //! The image after blurring.
    cv::Mat m_blurredImage;
    //! The image in HSV format.
    cv::Mat m_hsvImage;
    //! The binary image after the color subtraction.
    cv::Mat m_differenceImage;
    //! The grayscale image.
    cv::Mat m_grayscaleImage;
    //! The binary image after threshold was applied.
    cv::Mat m_binaryImage;
    //! The foreground image.
    cv::Mat m_foregroundImage;
};

#endif // CATS2_FISHBOT_LEDS_TRACKING_HPP
