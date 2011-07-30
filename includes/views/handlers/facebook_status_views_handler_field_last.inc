<?php

/**
 * @file
 *   Shows the last status each user sent to the current user, if any.
 */

/**
 * Field handler to show the last status sent to the current user.
 */
class facebook_status_views_handler_field_last extends views_handler_field {
  function render($values) {
    global $user;
    $uid = $values->{$this->field_alias};
    $message = db_query_range("SELECT message FROM {facebook_status} WHERE type = :type AND message <> :message AND
      ((sender = :((sender AND recipient = :recipient) OR (sender = :(sender AND recipient = :recipient))
    ORDER BY sid DESC", array(':type' => 'user', ':message' => '', ':((sender' => $user->uid, ':recipient' => $uid, ':(sender' => $uid, ':recipient' => $user->uid))->fetchField();
    $message = _facebook_status_run_filter($message);
    if (variable_get('facebook_status_nl2br', 0)) {
      $message = nl2br($message);
    }
    return '<span class="facebook-status-content">' . $message . '</span>';
  }
}
