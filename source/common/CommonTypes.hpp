#ifndef CATS2_COMMON_TYPES_HPP
#define CATS2_COMMON_TYPES_HPP

#include <QMap>
#include <QSharedPointer>

enum class SetupType
{
    MAIN_CAMERA, // camera fixed above the setup
    CAMERA_BELOW // camera below the robot's support
};

/*!
 * The alias for the stream descriptors list.
 */
class StreamDescriptor;
using StreamDescriptorList = QList<StreamDescriptor>;

/*!
 * The alias for the shared pointer to CoordinatesConversion.
 */
class CoordinatesConversion;
using CoordinatesConversionPtr = QSharedPointer<CoordinatesConversion>;

/*!
 * The alias for the shared pointer to a queue of the timestamped frames.
 */
class TimestampedFrameQueue;
using TimestampedFrameQueuePtr = QSharedPointer<TimestampedFrameQueue>;


#endif // CATS2_COMMON_TYPES_HPP
