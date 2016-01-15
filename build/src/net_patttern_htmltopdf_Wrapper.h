/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class net_patttern_htmltopdf_Wrapper */

#ifndef _Included_net_patttern_htmltopdf_Wrapper
#define _Included_net_patttern_htmltopdf_Wrapper
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     net_patttern_htmltopdf_Wrapper
 * Method:    init
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_init
  (JNIEnv *, jclass, jboolean);

/*
 * Class:     net_patttern_htmltopdf_Wrapper
 * Method:    setSource
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setSource
  (JNIEnv *, jclass, jstring);

/*
 * Class:     net_patttern_htmltopdf_Wrapper
 * Method:    setDestination
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setDestination
  (JNIEnv *, jclass, jstring);

/*
 * Class:     net_patttern_htmltopdf_Wrapper
 * Method:    setGlobalSettings
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setGlobalSettings
  (JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     net_patttern_htmltopdf_Wrapper
 * Method:    setObjectSettings
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setObjectSettings
  (JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     net_patttern_htmltopdf_Wrapper
 * Method:    convert
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_net_patttern_htmltopdf_Wrapper_convert
  (JNIEnv *, jclass);

/*
 * Class:     net_patttern_htmltopdf_Wrapper
 * Method:    release
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_release
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
