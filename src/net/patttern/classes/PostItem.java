package net.patttern.classes;

import com.sun.jna.Structure;

/**
 * Created by ebabenko on 07.12.15.
 */
public class PostItem extends Structure {
/*
  QString name;
  QString value;
  bool file;
*/
  public String name;
  public String value;
  public Boolean file;

  public PostItem() {
  }
}
